#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Vector3Stamped.h>
#include <geometry_msgs/Twist.h>

/*----------- Parameter ------------------*/
/*------------ robot dimension -----------*/
double encoder_wheel = 0.03;
double wheel_base_lr = 0.45;
double wheel_base_fb = 0.45;
double two_pi = 6.28319;
/*------------ robot speed ---------------*/
double left_motor_speed = 0;
double right_motor_speed = 0;
double speed_theta = 0;
/*------------ robot odometry ------------*/
double x_pos, y_pos, theta = 0;
/*------------ new variable --------------*/
double rate = 10;
/*------------ new variable --------------*/
double dt , dx, dy = 0.0;
double dth, dxy, vx = 0.0;
double vy, vth, gZ = 0.0;
/*------------ robot link ----------------*/
char base_link[] = "base_link";
char odom[] = "odom";
/*----------- class initial --------------*/

/*
ros::Time current_time;
ros::Time speed_time(0.0);
*/
/*----------- recieve motor speed -------*/
void motor_msg(const geometry_msgs::Vector3Stamped &motor_speed)
{
    left_motor_speed = motor_speed.vector.x;
    right_motor_speed = motor_speed.vector.y;
    gZ = motor_speed.vector.z;
}

int main(int argc, char **argv)
{
  
    /*---------- controller node --------*/
    ros::init(argc, argv, "robot_controller");
    ros::NodeHandle astrobot;
    ros::Publisher odom_pub = astrobot.advertise<nav_msgs::Odometry>("odom", 50);
    ros::Subscriber motor_speed = astrobot.subscribe("motor_speed", 50, motor_msg);
    tf::TransformBroadcaster odom_broadcaster;
    ros::Time current_time, last_time;
    current_time = ros::Time::now();
    last_time = ros::Time::now();
    ros::Rate r(rate);
    while (astrobot.ok())
    {
        ros::spinOnce();
        current_time = ros::Time::now();
        double dt = (current_time - last_time).toSec();

        dxy = ((left_motor_speed + right_motor_speed) * dt) / 2;
        dth = ((right_motor_speed - left_motor_speed) * dt) / wheel_base_fb;

        vx = (dt == 0) ? 0 : (left_motor_speed + right_motor_speed) / 2;
        vth = (dt == 0) ? 0 : (right_motor_speed - left_motor_speed) / (wheel_base_fb + wheel_base_lr) ;

        /*----------- odometry calculation --------*/
        dx = cos(dth) * dxy;
        dy = sin(dth) * dxy;

        x_pos += (cos(gZ) * dx - sin(gZ) * dy);
        y_pos += (sin(gZ) * dx - cos(gZ) * dy);
        theta += dth;

        if (theta >= two_pi)
            theta -= two_pi;
        if (theta <= -two_pi)
            theta += two_pi;

        /*----------- publish tranform -----------*/
        geometry_msgs::TransformStamped odom_trans;
        odom_trans.header.stamp = current_time;
        odom_trans.header.frame_id = odom;
        odom_trans.child_frame_id = base_link;
        odom_trans.transform.translation.x = x_pos;
        odom_trans.transform.translation.y = y_pos;
        odom_trans.transform.translation.z = 0.0;
        odom_trans.transform.rotation = tf::createQuaternionMsgFromYaw(gZ);
        odom_broadcaster.sendTransform(odom_trans);

        // next, we'll publish the odometry message over ROS
        nav_msgs::Odometry odom_msg;
        odom_msg.header.stamp = current_time;
        odom_msg.header.frame_id = odom;

        // set the position
        odom_msg.pose.pose.position.x = x_pos;
        odom_msg.pose.pose.position.y = y_pos;
        odom_msg.pose.pose.position.z = 0.00;
        odom_msg.pose.pose.orientation = tf::createQuaternionMsgFromYaw(gZ);

        // set the velocity
        odom_msg.child_frame_id = base_link;
        odom_msg.twist.twist.linear.x = vx;
        odom_msg.twist.twist.linear.y = vy;
        odom_msg.twist.twist.angular.z = vth;

        last_time = current_time;
        odom_pub.publish(odom_msg);
        r.sleep();
    }
}
