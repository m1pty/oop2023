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
include static/CMakeFiles/Tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include static/CMakeFiles/Tests.dir/compiler_depend.make

# Include the progress variables for this target.
include static/CMakeFiles/Tests.dir/progress.make

# Include the compile flags for this target's objects.
include static/CMakeFiles/Tests.dir/flags.make

static/CMakeFiles/Tests.dir/Tests/source/TestCase.cpp.o: static/CMakeFiles/Tests.dir/flags.make
static/CMakeFiles/Tests.dir/Tests/source/TestCase.cpp.o: ../static/Tests/source/TestCase.cpp
static/CMakeFiles/Tests.dir/Tests/source/TestCase.cpp.o: static/CMakeFiles/Tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/m1pty/university/oop2023/lab2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object static/CMakeFiles/Tests.dir/Tests/source/TestCase.cpp.o"
	cd /home/m1pty/university/oop2023/lab2/build/static && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT static/CMakeFiles/Tests.dir/Tests/source/TestCase.cpp.o -MF CMakeFiles/Tests.dir/Tests/source/TestCase.cpp.o.d -o CMakeFiles/Tests.dir/Tests/source/TestCase.cpp.o -c /home/m1pty/university/oop2023/lab2/static/Tests/source/TestCase.cpp

static/CMakeFiles/Tests.dir/Tests/source/TestCase.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tests.dir/Tests/source/TestCase.cpp.i"
	cd /home/m1pty/university/oop2023/lab2/build/static && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/m1pty/university/oop2023/lab2/static/Tests/source/TestCase.cpp > CMakeFiles/Tests.dir/Tests/source/TestCase.cpp.i

static/CMakeFiles/Tests.dir/Tests/source/TestCase.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tests.dir/Tests/source/TestCase.cpp.s"
	cd /home/m1pty/university/oop2023/lab2/build/static && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/m1pty/university/oop2023/lab2/static/Tests/source/TestCase.cpp -o CMakeFiles/Tests.dir/Tests/source/TestCase.cpp.s

# Object files for target Tests
Tests_OBJECTS = \
"CMakeFiles/Tests.dir/Tests/source/TestCase.cpp.o"

# External object files for target Tests
Tests_EXTERNAL_OBJECTS =

static/Tests: static/CMakeFiles/Tests.dir/Tests/source/TestCase.cpp.o
static/Tests: static/CMakeFiles/Tests.dir/build.make
static/Tests: _deps/catch2-build/src/libCatch2Main.a
static/Tests: static/Resource/libResource.a
static/Tests: static/Handlers/libHandlers.a
static/Tests: static/RDialogue/libRDialogue.a
static/Tests: static/TDialogue/libTDialogue.a
static/Tests: static/Table/libTable.a
static/Tests: _deps/catch2-build/src/libCatch2.a
static/Tests: static/RDialogue/libRDialogue.a
static/Tests: static/Resource/libResource.a
static/Tests: static/Handlers/libHandlers.a
static/Tests: static/CMakeFiles/Tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/m1pty/university/oop2023/lab2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Tests"
	cd /home/m1pty/university/oop2023/lab2/build/static && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
static/CMakeFiles/Tests.dir/build: static/Tests
.PHONY : static/CMakeFiles/Tests.dir/build

static/CMakeFiles/Tests.dir/clean:
	cd /home/m1pty/university/oop2023/lab2/build/static && $(CMAKE_COMMAND) -P CMakeFiles/Tests.dir/cmake_clean.cmake
.PHONY : static/CMakeFiles/Tests.dir/clean

static/CMakeFiles/Tests.dir/depend:
	cd /home/m1pty/university/oop2023/lab2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/m1pty/university/oop2023/lab2 /home/m1pty/university/oop2023/lab2/static /home/m1pty/university/oop2023/lab2/build /home/m1pty/university/oop2023/lab2/build/static /home/m1pty/university/oop2023/lab2/build/static/CMakeFiles/Tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : static/CMakeFiles/Tests.dir/depend

