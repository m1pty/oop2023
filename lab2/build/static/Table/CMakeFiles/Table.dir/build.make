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
include static/Table/CMakeFiles/Table.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include static/Table/CMakeFiles/Table.dir/compiler_depend.make

# Include the progress variables for this target.
include static/Table/CMakeFiles/Table.dir/progress.make

# Include the compile flags for this target's objects.
include static/Table/CMakeFiles/Table.dir/flags.make

static/Table/CMakeFiles/Table.dir/source/Table.cpp.o: static/Table/CMakeFiles/Table.dir/flags.make
static/Table/CMakeFiles/Table.dir/source/Table.cpp.o: ../static/Table/source/Table.cpp
static/Table/CMakeFiles/Table.dir/source/Table.cpp.o: static/Table/CMakeFiles/Table.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/m1pty/university/oop2023/lab2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object static/Table/CMakeFiles/Table.dir/source/Table.cpp.o"
	cd /home/m1pty/university/oop2023/lab2/build/static/Table && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT static/Table/CMakeFiles/Table.dir/source/Table.cpp.o -MF CMakeFiles/Table.dir/source/Table.cpp.o.d -o CMakeFiles/Table.dir/source/Table.cpp.o -c /home/m1pty/university/oop2023/lab2/static/Table/source/Table.cpp

static/Table/CMakeFiles/Table.dir/source/Table.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Table.dir/source/Table.cpp.i"
	cd /home/m1pty/university/oop2023/lab2/build/static/Table && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/m1pty/university/oop2023/lab2/static/Table/source/Table.cpp > CMakeFiles/Table.dir/source/Table.cpp.i

static/Table/CMakeFiles/Table.dir/source/Table.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Table.dir/source/Table.cpp.s"
	cd /home/m1pty/university/oop2023/lab2/build/static/Table && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/m1pty/university/oop2023/lab2/static/Table/source/Table.cpp -o CMakeFiles/Table.dir/source/Table.cpp.s

# Object files for target Table
Table_OBJECTS = \
"CMakeFiles/Table.dir/source/Table.cpp.o"

# External object files for target Table
Table_EXTERNAL_OBJECTS =

static/Table/libTable.a: static/Table/CMakeFiles/Table.dir/source/Table.cpp.o
static/Table/libTable.a: static/Table/CMakeFiles/Table.dir/build.make
static/Table/libTable.a: static/Table/CMakeFiles/Table.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/m1pty/university/oop2023/lab2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libTable.a"
	cd /home/m1pty/university/oop2023/lab2/build/static/Table && $(CMAKE_COMMAND) -P CMakeFiles/Table.dir/cmake_clean_target.cmake
	cd /home/m1pty/university/oop2023/lab2/build/static/Table && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Table.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
static/Table/CMakeFiles/Table.dir/build: static/Table/libTable.a
.PHONY : static/Table/CMakeFiles/Table.dir/build

static/Table/CMakeFiles/Table.dir/clean:
	cd /home/m1pty/university/oop2023/lab2/build/static/Table && $(CMAKE_COMMAND) -P CMakeFiles/Table.dir/cmake_clean.cmake
.PHONY : static/Table/CMakeFiles/Table.dir/clean

static/Table/CMakeFiles/Table.dir/depend:
	cd /home/m1pty/university/oop2023/lab2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/m1pty/university/oop2023/lab2 /home/m1pty/university/oop2023/lab2/static/Table /home/m1pty/university/oop2023/lab2/build /home/m1pty/university/oop2023/lab2/build/static/Table /home/m1pty/university/oop2023/lab2/build/static/Table/CMakeFiles/Table.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : static/Table/CMakeFiles/Table.dir/depend

