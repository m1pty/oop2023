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
CMAKE_SOURCE_DIR = /home/m1pty/university/oop2023/lab2/static

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/m1pty/university/oop2023/lab2/static/build

# Include any dependencies generated for this target.
include Handlers/CMakeFiles/Handlers.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Handlers/CMakeFiles/Handlers.dir/compiler_depend.make

# Include the progress variables for this target.
include Handlers/CMakeFiles/Handlers.dir/progress.make

# Include the compile flags for this target's objects.
include Handlers/CMakeFiles/Handlers.dir/flags.make

Handlers/CMakeFiles/Handlers.dir/source/Handlers.cpp.o: Handlers/CMakeFiles/Handlers.dir/flags.make
Handlers/CMakeFiles/Handlers.dir/source/Handlers.cpp.o: ../Handlers/source/Handlers.cpp
Handlers/CMakeFiles/Handlers.dir/source/Handlers.cpp.o: Handlers/CMakeFiles/Handlers.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/m1pty/university/oop2023/lab2/static/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Handlers/CMakeFiles/Handlers.dir/source/Handlers.cpp.o"
	cd /home/m1pty/university/oop2023/lab2/static/build/Handlers && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Handlers/CMakeFiles/Handlers.dir/source/Handlers.cpp.o -MF CMakeFiles/Handlers.dir/source/Handlers.cpp.o.d -o CMakeFiles/Handlers.dir/source/Handlers.cpp.o -c /home/m1pty/university/oop2023/lab2/static/Handlers/source/Handlers.cpp

Handlers/CMakeFiles/Handlers.dir/source/Handlers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Handlers.dir/source/Handlers.cpp.i"
	cd /home/m1pty/university/oop2023/lab2/static/build/Handlers && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/m1pty/university/oop2023/lab2/static/Handlers/source/Handlers.cpp > CMakeFiles/Handlers.dir/source/Handlers.cpp.i

Handlers/CMakeFiles/Handlers.dir/source/Handlers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Handlers.dir/source/Handlers.cpp.s"
	cd /home/m1pty/university/oop2023/lab2/static/build/Handlers && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/m1pty/university/oop2023/lab2/static/Handlers/source/Handlers.cpp -o CMakeFiles/Handlers.dir/source/Handlers.cpp.s

# Object files for target Handlers
Handlers_OBJECTS = \
"CMakeFiles/Handlers.dir/source/Handlers.cpp.o"

# External object files for target Handlers
Handlers_EXTERNAL_OBJECTS =

Handlers/libHandlers.a: Handlers/CMakeFiles/Handlers.dir/source/Handlers.cpp.o
Handlers/libHandlers.a: Handlers/CMakeFiles/Handlers.dir/build.make
Handlers/libHandlers.a: Handlers/CMakeFiles/Handlers.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/m1pty/university/oop2023/lab2/static/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libHandlers.a"
	cd /home/m1pty/university/oop2023/lab2/static/build/Handlers && $(CMAKE_COMMAND) -P CMakeFiles/Handlers.dir/cmake_clean_target.cmake
	cd /home/m1pty/university/oop2023/lab2/static/build/Handlers && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Handlers.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Handlers/CMakeFiles/Handlers.dir/build: Handlers/libHandlers.a
.PHONY : Handlers/CMakeFiles/Handlers.dir/build

Handlers/CMakeFiles/Handlers.dir/clean:
	cd /home/m1pty/university/oop2023/lab2/static/build/Handlers && $(CMAKE_COMMAND) -P CMakeFiles/Handlers.dir/cmake_clean.cmake
.PHONY : Handlers/CMakeFiles/Handlers.dir/clean

Handlers/CMakeFiles/Handlers.dir/depend:
	cd /home/m1pty/university/oop2023/lab2/static/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/m1pty/university/oop2023/lab2/static /home/m1pty/university/oop2023/lab2/static/Handlers /home/m1pty/university/oop2023/lab2/static/build /home/m1pty/university/oop2023/lab2/static/build/Handlers /home/m1pty/university/oop2023/lab2/static/build/Handlers/CMakeFiles/Handlers.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Handlers/CMakeFiles/Handlers.dir/depend

