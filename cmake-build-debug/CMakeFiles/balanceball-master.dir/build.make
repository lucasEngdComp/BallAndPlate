# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/assert-latomia/Downloads/clion-2019.2.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/assert-latomia/Downloads/clion-2019.2.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/assert-latomia/BallAndPlate

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/assert-latomia/BallAndPlate/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/balanceball-master.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/balanceball-master.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/balanceball-master.dir/flags.make

CMakeFiles/balanceball-master.dir/balanceball.cpp.o: CMakeFiles/balanceball-master.dir/flags.make
CMakeFiles/balanceball-master.dir/balanceball.cpp.o: ../balanceball.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/assert-latomia/BallAndPlate/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/balanceball-master.dir/balanceball.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/balanceball-master.dir/balanceball.cpp.o -c /home/assert-latomia/BallAndPlate/balanceball.cpp

CMakeFiles/balanceball-master.dir/balanceball.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/balanceball-master.dir/balanceball.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/assert-latomia/BallAndPlate/balanceball.cpp > CMakeFiles/balanceball-master.dir/balanceball.cpp.i

CMakeFiles/balanceball-master.dir/balanceball.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/balanceball-master.dir/balanceball.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/assert-latomia/BallAndPlate/balanceball.cpp -o CMakeFiles/balanceball-master.dir/balanceball.cpp.s

CMakeFiles/balanceball-master.dir/camera/camera.cpp.o: CMakeFiles/balanceball-master.dir/flags.make
CMakeFiles/balanceball-master.dir/camera/camera.cpp.o: ../camera/camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/assert-latomia/BallAndPlate/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/balanceball-master.dir/camera/camera.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/balanceball-master.dir/camera/camera.cpp.o -c /home/assert-latomia/BallAndPlate/camera/camera.cpp

CMakeFiles/balanceball-master.dir/camera/camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/balanceball-master.dir/camera/camera.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/assert-latomia/BallAndPlate/camera/camera.cpp > CMakeFiles/balanceball-master.dir/camera/camera.cpp.i

CMakeFiles/balanceball-master.dir/camera/camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/balanceball-master.dir/camera/camera.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/assert-latomia/BallAndPlate/camera/camera.cpp -o CMakeFiles/balanceball-master.dir/camera/camera.cpp.s

# Object files for target balanceball-master
balanceball__master_OBJECTS = \
"CMakeFiles/balanceball-master.dir/balanceball.cpp.o" \
"CMakeFiles/balanceball-master.dir/camera/camera.cpp.o"

# External object files for target balanceball-master
balanceball__master_EXTERNAL_OBJECTS =

balanceball-master: CMakeFiles/balanceball-master.dir/balanceball.cpp.o
balanceball-master: CMakeFiles/balanceball-master.dir/camera/camera.cpp.o
balanceball-master: CMakeFiles/balanceball-master.dir/build.make
balanceball-master: /usr/local/lib/libopencv_dnn.so.4.1.1
balanceball-master: /usr/local/lib/libopencv_gapi.so.4.1.1
balanceball-master: /usr/local/lib/libopencv_highgui.so.4.1.1
balanceball-master: /usr/local/lib/libopencv_ml.so.4.1.1
balanceball-master: /usr/local/lib/libopencv_objdetect.so.4.1.1
balanceball-master: /usr/local/lib/libopencv_photo.so.4.1.1
balanceball-master: /usr/local/lib/libopencv_stitching.so.4.1.1
balanceball-master: /usr/local/lib/libopencv_video.so.4.1.1
balanceball-master: /usr/local/lib/libopencv_videoio.so.4.1.1
balanceball-master: /usr/local/lib/libopencv_imgcodecs.so.4.1.1
balanceball-master: /usr/local/lib/libopencv_calib3d.so.4.1.1
balanceball-master: /usr/local/lib/libopencv_features2d.so.4.1.1
balanceball-master: /usr/local/lib/libopencv_flann.so.4.1.1
balanceball-master: /usr/local/lib/libopencv_imgproc.so.4.1.1
balanceball-master: /usr/local/lib/libopencv_core.so.4.1.1
balanceball-master: CMakeFiles/balanceball-master.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/assert-latomia/BallAndPlate/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable balanceball-master"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/balanceball-master.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/balanceball-master.dir/build: balanceball-master

.PHONY : CMakeFiles/balanceball-master.dir/build

CMakeFiles/balanceball-master.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/balanceball-master.dir/cmake_clean.cmake
.PHONY : CMakeFiles/balanceball-master.dir/clean

CMakeFiles/balanceball-master.dir/depend:
	cd /home/assert-latomia/BallAndPlate/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/assert-latomia/BallAndPlate /home/assert-latomia/BallAndPlate /home/assert-latomia/BallAndPlate/cmake-build-debug /home/assert-latomia/BallAndPlate/cmake-build-debug /home/assert-latomia/BallAndPlate/cmake-build-debug/CMakeFiles/balanceball-master.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/balanceball-master.dir/depend

