# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/astro-bot/robot_astro/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/astro-bot/robot_astro/build

# Include any dependencies generated for this target.
include openslam_gmapping/CMakeFiles/autoptr_test.dir/depend.make

# Include the progress variables for this target.
include openslam_gmapping/CMakeFiles/autoptr_test.dir/progress.make

# Include the compile flags for this target's objects.
include openslam_gmapping/CMakeFiles/autoptr_test.dir/flags.make

openslam_gmapping/CMakeFiles/autoptr_test.dir/utils/autoptr_test.cpp.o: openslam_gmapping/CMakeFiles/autoptr_test.dir/flags.make
openslam_gmapping/CMakeFiles/autoptr_test.dir/utils/autoptr_test.cpp.o: /home/astro-bot/robot_astro/src/openslam_gmapping/utils/autoptr_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/astro-bot/robot_astro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object openslam_gmapping/CMakeFiles/autoptr_test.dir/utils/autoptr_test.cpp.o"
	cd /home/astro-bot/robot_astro/build/openslam_gmapping && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/autoptr_test.dir/utils/autoptr_test.cpp.o -c /home/astro-bot/robot_astro/src/openslam_gmapping/utils/autoptr_test.cpp

openslam_gmapping/CMakeFiles/autoptr_test.dir/utils/autoptr_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/autoptr_test.dir/utils/autoptr_test.cpp.i"
	cd /home/astro-bot/robot_astro/build/openslam_gmapping && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/astro-bot/robot_astro/src/openslam_gmapping/utils/autoptr_test.cpp > CMakeFiles/autoptr_test.dir/utils/autoptr_test.cpp.i

openslam_gmapping/CMakeFiles/autoptr_test.dir/utils/autoptr_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/autoptr_test.dir/utils/autoptr_test.cpp.s"
	cd /home/astro-bot/robot_astro/build/openslam_gmapping && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/astro-bot/robot_astro/src/openslam_gmapping/utils/autoptr_test.cpp -o CMakeFiles/autoptr_test.dir/utils/autoptr_test.cpp.s

openslam_gmapping/CMakeFiles/autoptr_test.dir/utils/autoptr_test.cpp.o.requires:

.PHONY : openslam_gmapping/CMakeFiles/autoptr_test.dir/utils/autoptr_test.cpp.o.requires

openslam_gmapping/CMakeFiles/autoptr_test.dir/utils/autoptr_test.cpp.o.provides: openslam_gmapping/CMakeFiles/autoptr_test.dir/utils/autoptr_test.cpp.o.requires
	$(MAKE) -f openslam_gmapping/CMakeFiles/autoptr_test.dir/build.make openslam_gmapping/CMakeFiles/autoptr_test.dir/utils/autoptr_test.cpp.o.provides.build
.PHONY : openslam_gmapping/CMakeFiles/autoptr_test.dir/utils/autoptr_test.cpp.o.provides

openslam_gmapping/CMakeFiles/autoptr_test.dir/utils/autoptr_test.cpp.o.provides.build: openslam_gmapping/CMakeFiles/autoptr_test.dir/utils/autoptr_test.cpp.o


# Object files for target autoptr_test
autoptr_test_OBJECTS = \
"CMakeFiles/autoptr_test.dir/utils/autoptr_test.cpp.o"

# External object files for target autoptr_test
autoptr_test_EXTERNAL_OBJECTS =

/home/astro-bot/robot_astro/devel/lib/openslam_gmapping/autoptr_test: openslam_gmapping/CMakeFiles/autoptr_test.dir/utils/autoptr_test.cpp.o
/home/astro-bot/robot_astro/devel/lib/openslam_gmapping/autoptr_test: openslam_gmapping/CMakeFiles/autoptr_test.dir/build.make
/home/astro-bot/robot_astro/devel/lib/openslam_gmapping/autoptr_test: openslam_gmapping/CMakeFiles/autoptr_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/astro-bot/robot_astro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/astro-bot/robot_astro/devel/lib/openslam_gmapping/autoptr_test"
	cd /home/astro-bot/robot_astro/build/openslam_gmapping && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/autoptr_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
openslam_gmapping/CMakeFiles/autoptr_test.dir/build: /home/astro-bot/robot_astro/devel/lib/openslam_gmapping/autoptr_test

.PHONY : openslam_gmapping/CMakeFiles/autoptr_test.dir/build

openslam_gmapping/CMakeFiles/autoptr_test.dir/requires: openslam_gmapping/CMakeFiles/autoptr_test.dir/utils/autoptr_test.cpp.o.requires

.PHONY : openslam_gmapping/CMakeFiles/autoptr_test.dir/requires

openslam_gmapping/CMakeFiles/autoptr_test.dir/clean:
	cd /home/astro-bot/robot_astro/build/openslam_gmapping && $(CMAKE_COMMAND) -P CMakeFiles/autoptr_test.dir/cmake_clean.cmake
.PHONY : openslam_gmapping/CMakeFiles/autoptr_test.dir/clean

openslam_gmapping/CMakeFiles/autoptr_test.dir/depend:
	cd /home/astro-bot/robot_astro/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/astro-bot/robot_astro/src /home/astro-bot/robot_astro/src/openslam_gmapping /home/astro-bot/robot_astro/build /home/astro-bot/robot_astro/build/openslam_gmapping /home/astro-bot/robot_astro/build/openslam_gmapping/CMakeFiles/autoptr_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : openslam_gmapping/CMakeFiles/autoptr_test.dir/depend

