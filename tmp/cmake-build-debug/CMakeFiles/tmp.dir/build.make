# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_SOURCE_DIR = /Users/Igor/Documents/codeforces/tmp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Igor/Documents/codeforces/tmp/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/tmp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tmp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tmp.dir/flags.make

CMakeFiles/tmp.dir/A.cpp.o: CMakeFiles/tmp.dir/flags.make
CMakeFiles/tmp.dir/A.cpp.o: ../A.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Igor/Documents/codeforces/tmp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tmp.dir/A.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tmp.dir/A.cpp.o -c /Users/Igor/Documents/codeforces/tmp/A.cpp

CMakeFiles/tmp.dir/A.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tmp.dir/A.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Igor/Documents/codeforces/tmp/A.cpp > CMakeFiles/tmp.dir/A.cpp.i

CMakeFiles/tmp.dir/A.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tmp.dir/A.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Igor/Documents/codeforces/tmp/A.cpp -o CMakeFiles/tmp.dir/A.cpp.s

# Object files for target tmp
tmp_OBJECTS = \
"CMakeFiles/tmp.dir/A.cpp.o"

# External object files for target tmp
tmp_EXTERNAL_OBJECTS =

tmp: CMakeFiles/tmp.dir/A.cpp.o
tmp: CMakeFiles/tmp.dir/build.make
tmp: CMakeFiles/tmp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Igor/Documents/codeforces/tmp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tmp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tmp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tmp.dir/build: tmp

.PHONY : CMakeFiles/tmp.dir/build

CMakeFiles/tmp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tmp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tmp.dir/clean

CMakeFiles/tmp.dir/depend:
	cd /Users/Igor/Documents/codeforces/tmp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Igor/Documents/codeforces/tmp /Users/Igor/Documents/codeforces/tmp /Users/Igor/Documents/codeforces/tmp/cmake-build-debug /Users/Igor/Documents/codeforces/tmp/cmake-build-debug /Users/Igor/Documents/codeforces/tmp/cmake-build-debug/CMakeFiles/tmp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tmp.dir/depend

