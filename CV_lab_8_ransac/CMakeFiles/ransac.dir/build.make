# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = "/home/jai/Google Drive/Jacobs University/Fall 2017/Computer Vision/CV_lab_8_ransac"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/jai/Google Drive/Jacobs University/Fall 2017/Computer Vision/CV_lab_8_ransac"

# Include any dependencies generated for this target.
include CMakeFiles/ransac.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ransac.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ransac.dir/flags.make

CMakeFiles/ransac.dir/ransac.cpp.o: CMakeFiles/ransac.dir/flags.make
CMakeFiles/ransac.dir/ransac.cpp.o: ransac.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/jai/Google Drive/Jacobs University/Fall 2017/Computer Vision/CV_lab_8_ransac/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ransac.dir/ransac.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ransac.dir/ransac.cpp.o -c "/home/jai/Google Drive/Jacobs University/Fall 2017/Computer Vision/CV_lab_8_ransac/ransac.cpp"

CMakeFiles/ransac.dir/ransac.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ransac.dir/ransac.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/jai/Google Drive/Jacobs University/Fall 2017/Computer Vision/CV_lab_8_ransac/ransac.cpp" > CMakeFiles/ransac.dir/ransac.cpp.i

CMakeFiles/ransac.dir/ransac.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ransac.dir/ransac.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/jai/Google Drive/Jacobs University/Fall 2017/Computer Vision/CV_lab_8_ransac/ransac.cpp" -o CMakeFiles/ransac.dir/ransac.cpp.s

CMakeFiles/ransac.dir/ransac.cpp.o.requires:

.PHONY : CMakeFiles/ransac.dir/ransac.cpp.o.requires

CMakeFiles/ransac.dir/ransac.cpp.o.provides: CMakeFiles/ransac.dir/ransac.cpp.o.requires
	$(MAKE) -f CMakeFiles/ransac.dir/build.make CMakeFiles/ransac.dir/ransac.cpp.o.provides.build
.PHONY : CMakeFiles/ransac.dir/ransac.cpp.o.provides

CMakeFiles/ransac.dir/ransac.cpp.o.provides.build: CMakeFiles/ransac.dir/ransac.cpp.o


# Object files for target ransac
ransac_OBJECTS = \
"CMakeFiles/ransac.dir/ransac.cpp.o"

# External object files for target ransac
ransac_EXTERNAL_OBJECTS =

ransac: CMakeFiles/ransac.dir/ransac.cpp.o
ransac: CMakeFiles/ransac.dir/build.make
ransac: CMakeFiles/ransac.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/jai/Google Drive/Jacobs University/Fall 2017/Computer Vision/CV_lab_8_ransac/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ransac"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ransac.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ransac.dir/build: ransac

.PHONY : CMakeFiles/ransac.dir/build

CMakeFiles/ransac.dir/requires: CMakeFiles/ransac.dir/ransac.cpp.o.requires

.PHONY : CMakeFiles/ransac.dir/requires

CMakeFiles/ransac.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ransac.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ransac.dir/clean

CMakeFiles/ransac.dir/depend:
	cd "/home/jai/Google Drive/Jacobs University/Fall 2017/Computer Vision/CV_lab_8_ransac" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/jai/Google Drive/Jacobs University/Fall 2017/Computer Vision/CV_lab_8_ransac" "/home/jai/Google Drive/Jacobs University/Fall 2017/Computer Vision/CV_lab_8_ransac" "/home/jai/Google Drive/Jacobs University/Fall 2017/Computer Vision/CV_lab_8_ransac" "/home/jai/Google Drive/Jacobs University/Fall 2017/Computer Vision/CV_lab_8_ransac" "/home/jai/Google Drive/Jacobs University/Fall 2017/Computer Vision/CV_lab_8_ransac/CMakeFiles/ransac.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ransac.dir/depend
