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
include JsonUtils/CMakeFiles/JsonUtils.dir/depend.make

# Include the progress variables for this target.
include JsonUtils/CMakeFiles/JsonUtils.dir/progress.make

# Include the compile flags for this target's objects.
include JsonUtils/CMakeFiles/JsonUtils.dir/flags.make

JsonUtils/CMakeFiles/JsonUtils.dir/JsonUtils.cpp.obj: JsonUtils/CMakeFiles/JsonUtils.dir/flags.make
JsonUtils/CMakeFiles/JsonUtils.dir/JsonUtils.cpp.obj: JsonUtils/CMakeFiles/JsonUtils.dir/includes_CXX.rsp
JsonUtils/CMakeFiles/JsonUtils.dir/JsonUtils.cpp.obj: ../JsonUtils/JsonUtils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\huoyushi\Documents\GUGAODAQ\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object JsonUtils/CMakeFiles/JsonUtils.dir/JsonUtils.cpp.obj"
	cd /d C:\Users\huoyushi\Documents\GUGAODAQ\build\JsonUtils && C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\JsonUtils.dir\JsonUtils.cpp.obj -c C:\Users\huoyushi\Documents\GUGAODAQ\JsonUtils\JsonUtils.cpp

JsonUtils/CMakeFiles/JsonUtils.dir/JsonUtils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/JsonUtils.dir/JsonUtils.cpp.i"
	cd /d C:\Users\huoyushi\Documents\GUGAODAQ\build\JsonUtils && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\huoyushi\Documents\GUGAODAQ\JsonUtils\JsonUtils.cpp > CMakeFiles\JsonUtils.dir\JsonUtils.cpp.i

JsonUtils/CMakeFiles/JsonUtils.dir/JsonUtils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/JsonUtils.dir/JsonUtils.cpp.s"
	cd /d C:\Users\huoyushi\Documents\GUGAODAQ\build\JsonUtils && C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\huoyushi\Documents\GUGAODAQ\JsonUtils\JsonUtils.cpp -o CMakeFiles\JsonUtils.dir\JsonUtils.cpp.s

JsonUtils/CMakeFiles/JsonUtils.dir/JsonUtils.cpp.obj.requires:

.PHONY : JsonUtils/CMakeFiles/JsonUtils.dir/JsonUtils.cpp.obj.requires

JsonUtils/CMakeFiles/JsonUtils.dir/JsonUtils.cpp.obj.provides: JsonUtils/CMakeFiles/JsonUtils.dir/JsonUtils.cpp.obj.requires
	$(MAKE) -f JsonUtils\CMakeFiles\JsonUtils.dir\build.make JsonUtils/CMakeFiles/JsonUtils.dir/JsonUtils.cpp.obj.provides.build
.PHONY : JsonUtils/CMakeFiles/JsonUtils.dir/JsonUtils.cpp.obj.provides

JsonUtils/CMakeFiles/JsonUtils.dir/JsonUtils.cpp.obj.provides.build: JsonUtils/CMakeFiles/JsonUtils.dir/JsonUtils.cpp.obj


# Object files for target JsonUtils
JsonUtils_OBJECTS = \
"CMakeFiles/JsonUtils.dir/JsonUtils.cpp.obj"

# External object files for target JsonUtils
JsonUtils_EXTERNAL_OBJECTS =

bin/libJsonUtils.dll: JsonUtils/CMakeFiles/JsonUtils.dir/JsonUtils.cpp.obj
bin/libJsonUtils.dll: JsonUtils/CMakeFiles/JsonUtils.dir/build.make
bin/libJsonUtils.dll: JsonUtils/CMakeFiles/JsonUtils.dir/linklibs.rsp
bin/libJsonUtils.dll: JsonUtils/CMakeFiles/JsonUtils.dir/objects1.rsp
bin/libJsonUtils.dll: JsonUtils/CMakeFiles/JsonUtils.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\huoyushi\Documents\GUGAODAQ\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library ..\bin\libJsonUtils.dll"
	cd /d C:\Users\huoyushi\Documents\GUGAODAQ\build\JsonUtils && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\JsonUtils.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
JsonUtils/CMakeFiles/JsonUtils.dir/build: bin/libJsonUtils.dll

.PHONY : JsonUtils/CMakeFiles/JsonUtils.dir/build

JsonUtils/CMakeFiles/JsonUtils.dir/requires: JsonUtils/CMakeFiles/JsonUtils.dir/JsonUtils.cpp.obj.requires

.PHONY : JsonUtils/CMakeFiles/JsonUtils.dir/requires

JsonUtils/CMakeFiles/JsonUtils.dir/clean:
	cd /d C:\Users\huoyushi\Documents\GUGAODAQ\build\JsonUtils && $(CMAKE_COMMAND) -P CMakeFiles\JsonUtils.dir\cmake_clean.cmake
.PHONY : JsonUtils/CMakeFiles/JsonUtils.dir/clean

JsonUtils/CMakeFiles/JsonUtils.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\huoyushi\Documents\GUGAODAQ C:\Users\huoyushi\Documents\GUGAODAQ\JsonUtils C:\Users\huoyushi\Documents\GUGAODAQ\build C:\Users\huoyushi\Documents\GUGAODAQ\build\JsonUtils C:\Users\huoyushi\Documents\GUGAODAQ\build\JsonUtils\CMakeFiles\JsonUtils.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : JsonUtils/CMakeFiles/JsonUtils.dir/depend

