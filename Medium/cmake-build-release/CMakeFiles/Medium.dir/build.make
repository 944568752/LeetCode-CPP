# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /tmp/tmp.mnbFSZZwbT

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /tmp/tmp.mnbFSZZwbT/cmake-build-release

# Include any dependencies generated for this target.
include CMakeFiles/Medium.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Medium.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Medium.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Medium.dir/flags.make

CMakeFiles/Medium.dir/sortColors.cpp.o: CMakeFiles/Medium.dir/flags.make
CMakeFiles/Medium.dir/sortColors.cpp.o: ../sortColors.cpp
CMakeFiles/Medium.dir/sortColors.cpp.o: CMakeFiles/Medium.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/tmp.mnbFSZZwbT/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Medium.dir/sortColors.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Medium.dir/sortColors.cpp.o -MF CMakeFiles/Medium.dir/sortColors.cpp.o.d -o CMakeFiles/Medium.dir/sortColors.cpp.o -c /tmp/tmp.mnbFSZZwbT/sortColors.cpp

CMakeFiles/Medium.dir/sortColors.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Medium.dir/sortColors.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/tmp.mnbFSZZwbT/sortColors.cpp > CMakeFiles/Medium.dir/sortColors.cpp.i

CMakeFiles/Medium.dir/sortColors.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Medium.dir/sortColors.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/tmp.mnbFSZZwbT/sortColors.cpp -o CMakeFiles/Medium.dir/sortColors.cpp.s

# Object files for target Medium
Medium_OBJECTS = \
"CMakeFiles/Medium.dir/sortColors.cpp.o"

# External object files for target Medium
Medium_EXTERNAL_OBJECTS =

Medium: CMakeFiles/Medium.dir/sortColors.cpp.o
Medium: CMakeFiles/Medium.dir/build.make
Medium: CMakeFiles/Medium.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/tmp.mnbFSZZwbT/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Medium"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Medium.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Medium.dir/build: Medium
.PHONY : CMakeFiles/Medium.dir/build

CMakeFiles/Medium.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Medium.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Medium.dir/clean

CMakeFiles/Medium.dir/depend:
	cd /tmp/tmp.mnbFSZZwbT/cmake-build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/tmp.mnbFSZZwbT /tmp/tmp.mnbFSZZwbT /tmp/tmp.mnbFSZZwbT/cmake-build-release /tmp/tmp.mnbFSZZwbT/cmake-build-release /tmp/tmp.mnbFSZZwbT/cmake-build-release/CMakeFiles/Medium.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Medium.dir/depend

