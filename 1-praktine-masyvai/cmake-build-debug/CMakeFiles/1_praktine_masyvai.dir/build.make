# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = "D:\coding\CLion\CLion 2024.2.1\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "D:\coding\CLion\CLion 2024.2.1\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\coding\algoritmai-duomenu-strukturos\1-praktine-masyvai

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\coding\algoritmai-duomenu-strukturos\1-praktine-masyvai\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/1_praktine_masyvai.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/1_praktine_masyvai.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/1_praktine_masyvai.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/1_praktine_masyvai.dir/flags.make

CMakeFiles/1_praktine_masyvai.dir/main.cpp.obj: CMakeFiles/1_praktine_masyvai.dir/flags.make
CMakeFiles/1_praktine_masyvai.dir/main.cpp.obj: D:/coding/algoritmai-duomenu-strukturos/1-praktine-masyvai/main.cpp
CMakeFiles/1_praktine_masyvai.dir/main.cpp.obj: CMakeFiles/1_praktine_masyvai.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\coding\algoritmai-duomenu-strukturos\1-praktine-masyvai\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/1_praktine_masyvai.dir/main.cpp.obj"
	"D:\coding\CLion\CLion 2024.2.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/1_praktine_masyvai.dir/main.cpp.obj -MF CMakeFiles\1_praktine_masyvai.dir\main.cpp.obj.d -o CMakeFiles\1_praktine_masyvai.dir\main.cpp.obj -c D:\coding\algoritmai-duomenu-strukturos\1-praktine-masyvai\main.cpp

CMakeFiles/1_praktine_masyvai.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/1_praktine_masyvai.dir/main.cpp.i"
	"D:\coding\CLion\CLion 2024.2.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\coding\algoritmai-duomenu-strukturos\1-praktine-masyvai\main.cpp > CMakeFiles\1_praktine_masyvai.dir\main.cpp.i

CMakeFiles/1_praktine_masyvai.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/1_praktine_masyvai.dir/main.cpp.s"
	"D:\coding\CLion\CLion 2024.2.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\coding\algoritmai-duomenu-strukturos\1-praktine-masyvai\main.cpp -o CMakeFiles\1_praktine_masyvai.dir\main.cpp.s

# Object files for target 1_praktine_masyvai
1_praktine_masyvai_OBJECTS = \
"CMakeFiles/1_praktine_masyvai.dir/main.cpp.obj"

# External object files for target 1_praktine_masyvai
1_praktine_masyvai_EXTERNAL_OBJECTS =

1_praktine_masyvai.exe: CMakeFiles/1_praktine_masyvai.dir/main.cpp.obj
1_praktine_masyvai.exe: CMakeFiles/1_praktine_masyvai.dir/build.make
1_praktine_masyvai.exe: CMakeFiles/1_praktine_masyvai.dir/linkLibs.rsp
1_praktine_masyvai.exe: CMakeFiles/1_praktine_masyvai.dir/objects1.rsp
1_praktine_masyvai.exe: CMakeFiles/1_praktine_masyvai.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:\coding\algoritmai-duomenu-strukturos\1-praktine-masyvai\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 1_praktine_masyvai.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\1_praktine_masyvai.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/1_praktine_masyvai.dir/build: 1_praktine_masyvai.exe
.PHONY : CMakeFiles/1_praktine_masyvai.dir/build

CMakeFiles/1_praktine_masyvai.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\1_praktine_masyvai.dir\cmake_clean.cmake
.PHONY : CMakeFiles/1_praktine_masyvai.dir/clean

CMakeFiles/1_praktine_masyvai.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\coding\algoritmai-duomenu-strukturos\1-praktine-masyvai D:\coding\algoritmai-duomenu-strukturos\1-praktine-masyvai D:\coding\algoritmai-duomenu-strukturos\1-praktine-masyvai\cmake-build-debug D:\coding\algoritmai-duomenu-strukturos\1-praktine-masyvai\cmake-build-debug D:\coding\algoritmai-duomenu-strukturos\1-praktine-masyvai\cmake-build-debug\CMakeFiles\1_praktine_masyvai.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/1_praktine_masyvai.dir/depend

