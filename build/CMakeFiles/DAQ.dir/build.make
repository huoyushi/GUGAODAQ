# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.10

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\CMake\bin\cmake.exe

# The command to remove a file.
RM = C:\CMake\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\huoyushi\Documents\GUGAODAQ

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\huoyushi\Documents\GUGAODAQ\build

# Include any dependencies generated for this target.
include CMakeFiles/DAQ.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DAQ.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DAQ.dir/flags.make

CMakeFiles/DAQ.dir/main.cpp.obj: CMakeFiles/DAQ.dir/flags.make
CMakeFiles/DAQ.dir/main.cpp.obj: CMakeFiles/DAQ.dir/includes_CXX.rsp
CMakeFiles/DAQ.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\huoyushi\Documents\GUGAODAQ\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DAQ.dir/main.cpp.obj"
	cd /d C:\Users\huoyushi\Documents\GUGAODAQ\build && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\DAQ.dir\main.cpp.obj -c C:\Users\huoyushi\Documents\GUGAODAQ\main.cpp

CMakeFiles/DAQ.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DAQ.dir/main.cpp.i"
	cd /d C:\Users\huoyushi\Documents\GUGAODAQ\build && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\huoyushi\Documents\GUGAODAQ\main.cpp > CMakeFiles\DAQ.dir\main.cpp.i

CMakeFiles/DAQ.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DAQ.dir/main.cpp.s"
	cd /d C:\Users\huoyushi\Documents\GUGAODAQ\build && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\huoyushi\Documents\GUGAODAQ\main.cpp -o CMakeFiles\DAQ.dir\main.cpp.s

CMakeFiles/DAQ.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/DAQ.dir/main.cpp.obj.requires

CMakeFiles/DAQ.dir/main.cpp.obj.provides: CMakeFiles/DAQ.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\DAQ.dir\build.make CMakeFiles/DAQ.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/DAQ.dir/main.cpp.obj.provides

CMakeFiles/DAQ.dir/main.cpp.obj.provides.build: CMakeFiles/DAQ.dir/main.cpp.obj


# Object files for target DAQ
DAQ_OBJECTS = \
"CMakeFiles/DAQ.dir/main.cpp.obj"

# External object files for target DAQ
DAQ_EXTERNAL_OBJECTS =

bin/DAQ.exe: CMakeFiles/DAQ.dir/main.cpp.obj
bin/DAQ.exe: CMakeFiles/DAQ.dir/build.make
bin/DAQ.exe: bin/libNetSocket.dll.a
bin/DAQ.exe: bin/libJsonUtils.dll.a
bin/DAQ.exe: CMakeFiles/DAQ.dir/linklibs.rsp
bin/DAQ.exe: CMakeFiles/DAQ.dir/objects1.rsp
bin/DAQ.exe: CMakeFiles/DAQ.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\huoyushi\Documents\GUGAODAQ\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin\DAQ.exe"
	cd /d C:\Users\huoyushi\Documents\GUGAODAQ\build && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\DAQ.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DAQ.dir/build: bin/DAQ.exe

.PHONY : CMakeFiles/DAQ.dir/build

CMakeFiles/DAQ.dir/requires: CMakeFiles/DAQ.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/DAQ.dir/requires

CMakeFiles/DAQ.dir/clean:
	cd /d C:\Users\huoyushi\Documents\GUGAODAQ\build && $(CMAKE_COMMAND) -P CMakeFiles\DAQ.dir\cmake_clean.cmake
.PHONY : CMakeFiles/DAQ.dir/clean

CMakeFiles/DAQ.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\huoyushi\Documents\GUGAODAQ C:\Users\huoyushi\Documents\GUGAODAQ C:\Users\huoyushi\Documents\GUGAODAQ\build C:\Users\huoyushi\Documents\GUGAODAQ\build C:\Users\huoyushi\Documents\GUGAODAQ\build\CMakeFiles\DAQ.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DAQ.dir/depend

