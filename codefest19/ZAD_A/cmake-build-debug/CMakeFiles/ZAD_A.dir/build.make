# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Igor/Documents/codeforces/codefest19/ZAD_A

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Igor/Documents/codeforces/codefest19/ZAD_A/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ZAD_A.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ZAD_A.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ZAD_A.dir/flags.make

CMakeFiles/ZAD_A.dir/main.cpp.o: CMakeFiles/ZAD_A.dir/flags.make
CMakeFiles/ZAD_A.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Igor/Documents/codeforces/codefest19/ZAD_A/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ZAD_A.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ZAD_A.dir/main.cpp.o -c /Users/Igor/Documents/codeforces/codefest19/ZAD_A/main.cpp

CMakeFiles/ZAD_A.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ZAD_A.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Igor/Documents/codeforces/codefest19/ZAD_A/main.cpp > CMakeFiles/ZAD_A.dir/main.cpp.i

CMakeFiles/ZAD_A.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ZAD_A.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Igor/Documents/codeforces/codefest19/ZAD_A/main.cpp -o CMakeFiles/ZAD_A.dir/main.cpp.s

# Object files for target ZAD_A
ZAD_A_OBJECTS = \
"CMakeFiles/ZAD_A.dir/main.cpp.o"

# External object files for target ZAD_A
ZAD_A_EXTERNAL_OBJECTS =

ZAD_A: CMakeFiles/ZAD_A.dir/main.cpp.o
ZAD_A: CMakeFiles/ZAD_A.dir/build.make
ZAD_A: CMakeFiles/ZAD_A.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Igor/Documents/codeforces/codefest19/ZAD_A/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ZAD_A"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ZAD_A.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ZAD_A.dir/build: ZAD_A

.PHONY : CMakeFiles/ZAD_A.dir/build

CMakeFiles/ZAD_A.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ZAD_A.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ZAD_A.dir/clean

CMakeFiles/ZAD_A.dir/depend:
	cd /Users/Igor/Documents/codeforces/codefest19/ZAD_A/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Igor/Documents/codeforces/codefest19/ZAD_A /Users/Igor/Documents/codeforces/codefest19/ZAD_A /Users/Igor/Documents/codeforces/codefest19/ZAD_A/cmake-build-debug /Users/Igor/Documents/codeforces/codefest19/ZAD_A/cmake-build-debug /Users/Igor/Documents/codeforces/codefest19/ZAD_A/cmake-build-debug/CMakeFiles/ZAD_A.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ZAD_A.dir/depend
