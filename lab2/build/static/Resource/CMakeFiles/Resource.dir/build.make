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
CMAKE_SOURCE_DIR = /home/m1pty/university/oop2023/lab2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/m1pty/university/oop2023/lab2/build

# Include any dependencies generated for this target.
include static/Resource/CMakeFiles/Resource.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include static/Resource/CMakeFiles/Resource.dir/compiler_depend.make

# Include the progress variables for this target.
include static/Resource/CMakeFiles/Resource.dir/progress.make

# Include the compile flags for this target's objects.
include static/Resource/CMakeFiles/Resource.dir/flags.make

static/Resource/CMakeFiles/Resource.dir/source/Resource.cpp.o: static/Resource/CMakeFiles/Resource.dir/flags.make
static/Resource/CMakeFiles/Resource.dir/source/Resource.cpp.o: ../static/Resource/source/Resource.cpp
static/Resource/CMakeFiles/Resource.dir/source/Resource.cpp.o: static/Resource/CMakeFiles/Resource.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/m1pty/university/oop2023/lab2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object static/Resource/CMakeFiles/Resource.dir/source/Resource.cpp.o"
	cd /home/m1pty/university/oop2023/lab2/build/static/Resource && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT static/Resource/CMakeFiles/Resource.dir/source/Resource.cpp.o -MF CMakeFiles/Resource.dir/source/Resource.cpp.o.d -o CMakeFiles/Resource.dir/source/Resource.cpp.o -c /home/m1pty/university/oop2023/lab2/static/Resource/source/Resource.cpp

static/Resource/CMakeFiles/Resource.dir/source/Resource.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Resource.dir/source/Resource.cpp.i"
	cd /home/m1pty/university/oop2023/lab2/build/static/Resource && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/m1pty/university/oop2023/lab2/static/Resource/source/Resource.cpp > CMakeFiles/Resource.dir/source/Resource.cpp.i

static/Resource/CMakeFiles/Resource.dir/source/Resource.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Resource.dir/source/Resource.cpp.s"
	cd /home/m1pty/university/oop2023/lab2/build/static/Resource && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/m1pty/university/oop2023/lab2/static/Resource/source/Resource.cpp -o CMakeFiles/Resource.dir/source/Resource.cpp.s

# Object files for target Resource
Resource_OBJECTS = \
"CMakeFiles/Resource.dir/source/Resource.cpp.o"

# External object files for target Resource
Resource_EXTERNAL_OBJECTS =

static/Resource/libResource.a: static/Resource/CMakeFiles/Resource.dir/source/Resource.cpp.o
static/Resource/libResource.a: static/Resource/CMakeFiles/Resource.dir/build.make
static/Resource/libResource.a: static/Resource/CMakeFiles/Resource.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/m1pty/university/oop2023/lab2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libResource.a"
	cd /home/m1pty/university/oop2023/lab2/build/static/Resource && $(CMAKE_COMMAND) -P CMakeFiles/Resource.dir/cmake_clean_target.cmake
	cd /home/m1pty/university/oop2023/lab2/build/static/Resource && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Resource.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
static/Resource/CMakeFiles/Resource.dir/build: static/Resource/libResource.a
.PHONY : static/Resource/CMakeFiles/Resource.dir/build

static/Resource/CMakeFiles/Resource.dir/clean:
	cd /home/m1pty/university/oop2023/lab2/build/static/Resource && $(CMAKE_COMMAND) -P CMakeFiles/Resource.dir/cmake_clean.cmake
.PHONY : static/Resource/CMakeFiles/Resource.dir/clean

static/Resource/CMakeFiles/Resource.dir/depend:
	cd /home/m1pty/university/oop2023/lab2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/m1pty/university/oop2023/lab2 /home/m1pty/university/oop2023/lab2/static/Resource /home/m1pty/university/oop2023/lab2/build /home/m1pty/university/oop2023/lab2/build/static/Resource /home/m1pty/university/oop2023/lab2/build/static/Resource/CMakeFiles/Resource.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : static/Resource/CMakeFiles/Resource.dir/depend

