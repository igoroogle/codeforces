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
CMAKE_SOURCE_DIR = /Users/Igor/Documents/codeforces/div581

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Igor/Documents/codeforces/div581/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/div581.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/div581.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/div581.dir/flags.make

CMakeFiles/div581.dir/C.cpp.o: CMakeFiles/div581.dir/flags.make
CMakeFiles/div581.dir/C.cpp.o: ../C.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Igor/Documents/codeforces/div581/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/div581.dir/C.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/div581.dir/C.cpp.o -c /Users/Igor/Documents/codeforces/div581/C.cpp

CMakeFiles/div581.dir/C.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/div581.dir/C.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Igor/Documents/codeforces/div581/C.cpp > CMakeFiles/div581.dir/C.cpp.i

CMakeFiles/div581.dir/C.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/div581.dir/C.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Igor/Documents/codeforces/div581/C.cpp -o CMakeFiles/div581.dir/C.cpp.s

# Object files for target div581
div581_OBJECTS = \
"CMakeFiles/div581.dir/C.cpp.o"

# External object files for target div581
div581_EXTERNAL_OBJECTS =

div581: CMakeFiles/div581.dir/C.cpp.o
div581: CMakeFiles/div581.dir/build.make
div581: CMakeFiles/div581.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Igor/Documents/codeforces/div581/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable div581"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/div581.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/div581.dir/build: div581

.PHONY : CMakeFiles/div581.dir/build

CMakeFiles/div581.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/div581.dir/cmake_clean.cmake
.PHONY : CMakeFiles/div581.dir/clean

CMakeFiles/div581.dir/depend:
	cd /Users/Igor/Documents/codeforces/div581/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Igor/Documents/codeforces/div581 /Users/Igor/Documents/codeforces/div581 /Users/Igor/Documents/codeforces/div581/cmake-build-debug /Users/Igor/Documents/codeforces/div581/cmake-build-debug /Users/Igor/Documents/codeforces/div581/cmake-build-debug/CMakeFiles/div581.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/div581.dir/depend

