# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\mosta\CLionProjects\MonstersHotel

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\mosta\CLionProjects\MonstersHotel\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/MonstersHotel.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MonstersHotel.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MonstersHotel.dir/flags.make

CMakeFiles/MonstersHotel.dir/main.cpp.obj: CMakeFiles/MonstersHotel.dir/flags.make
CMakeFiles/MonstersHotel.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mosta\CLionProjects\MonstersHotel\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MonstersHotel.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\MonstersHotel.dir\main.cpp.obj -c C:\Users\mosta\CLionProjects\MonstersHotel\main.cpp

CMakeFiles/MonstersHotel.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MonstersHotel.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mosta\CLionProjects\MonstersHotel\main.cpp > CMakeFiles\MonstersHotel.dir\main.cpp.i

CMakeFiles/MonstersHotel.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MonstersHotel.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mosta\CLionProjects\MonstersHotel\main.cpp -o CMakeFiles\MonstersHotel.dir\main.cpp.s

# Object files for target MonstersHotel
MonstersHotel_OBJECTS = \
"CMakeFiles/MonstersHotel.dir/main.cpp.obj"

# External object files for target MonstersHotel
MonstersHotel_EXTERNAL_OBJECTS =

MonstersHotel.exe: CMakeFiles/MonstersHotel.dir/main.cpp.obj
MonstersHotel.exe: CMakeFiles/MonstersHotel.dir/build.make
MonstersHotel.exe: CMakeFiles/MonstersHotel.dir/linklibs.rsp
MonstersHotel.exe: CMakeFiles/MonstersHotel.dir/objects1.rsp
MonstersHotel.exe: CMakeFiles/MonstersHotel.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\mosta\CLionProjects\MonstersHotel\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MonstersHotel.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\MonstersHotel.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MonstersHotel.dir/build: MonstersHotel.exe

.PHONY : CMakeFiles/MonstersHotel.dir/build

CMakeFiles/MonstersHotel.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\MonstersHotel.dir\cmake_clean.cmake
.PHONY : CMakeFiles/MonstersHotel.dir/clean

CMakeFiles/MonstersHotel.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\mosta\CLionProjects\MonstersHotel C:\Users\mosta\CLionProjects\MonstersHotel C:\Users\mosta\CLionProjects\MonstersHotel\cmake-build-debug C:\Users\mosta\CLionProjects\MonstersHotel\cmake-build-debug C:\Users\mosta\CLionProjects\MonstersHotel\cmake-build-debug\CMakeFiles\MonstersHotel.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MonstersHotel.dir/depend

