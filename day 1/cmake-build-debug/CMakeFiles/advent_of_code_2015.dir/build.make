# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\MONSTER\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\202.6948.80\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\MONSTER\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\202.6948.80\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\MONSTER\Documents\github\advent-of-code-2015\day 1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\MONSTER\Documents\github\advent-of-code-2015\day 1\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/advent_of_code_2015.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/advent_of_code_2015.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/advent_of_code_2015.dir/flags.make

CMakeFiles/advent_of_code_2015.dir/main.cpp.obj: CMakeFiles/advent_of_code_2015.dir/flags.make
CMakeFiles/advent_of_code_2015.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\MONSTER\Documents\github\advent-of-code-2015\day 1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/advent_of_code_2015.dir/main.cpp.obj"
	C:\TDM-GCC-64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\advent_of_code_2015.dir\main.cpp.obj -c "C:\Users\MONSTER\Documents\github\advent-of-code-2015\day 1\main.cpp"

CMakeFiles/advent_of_code_2015.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/advent_of_code_2015.dir/main.cpp.i"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\MONSTER\Documents\github\advent-of-code-2015\day 1\main.cpp" > CMakeFiles\advent_of_code_2015.dir\main.cpp.i

CMakeFiles/advent_of_code_2015.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/advent_of_code_2015.dir/main.cpp.s"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\MONSTER\Documents\github\advent-of-code-2015\day 1\main.cpp" -o CMakeFiles\advent_of_code_2015.dir\main.cpp.s

# Object files for target advent_of_code_2015
advent_of_code_2015_OBJECTS = \
"CMakeFiles/advent_of_code_2015.dir/main.cpp.obj"

# External object files for target advent_of_code_2015
advent_of_code_2015_EXTERNAL_OBJECTS =

advent_of_code_2015.exe: CMakeFiles/advent_of_code_2015.dir/main.cpp.obj
advent_of_code_2015.exe: CMakeFiles/advent_of_code_2015.dir/build.make
advent_of_code_2015.exe: CMakeFiles/advent_of_code_2015.dir/linklibs.rsp
advent_of_code_2015.exe: CMakeFiles/advent_of_code_2015.dir/objects1.rsp
advent_of_code_2015.exe: CMakeFiles/advent_of_code_2015.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\MONSTER\Documents\github\advent-of-code-2015\day 1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable advent_of_code_2015.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\advent_of_code_2015.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/advent_of_code_2015.dir/build: advent_of_code_2015.exe

.PHONY : CMakeFiles/advent_of_code_2015.dir/build

CMakeFiles/advent_of_code_2015.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\advent_of_code_2015.dir\cmake_clean.cmake
.PHONY : CMakeFiles/advent_of_code_2015.dir/clean

CMakeFiles/advent_of_code_2015.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\MONSTER\Documents\github\advent-of-code-2015\day 1" "C:\Users\MONSTER\Documents\github\advent-of-code-2015\day 1" "C:\Users\MONSTER\Documents\github\advent-of-code-2015\day 1\cmake-build-debug" "C:\Users\MONSTER\Documents\github\advent-of-code-2015\day 1\cmake-build-debug" "C:\Users\MONSTER\Documents\github\advent-of-code-2015\day 1\cmake-build-debug\CMakeFiles\advent_of_code_2015.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/advent_of_code_2015.dir/depend

