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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2024.2.0.1\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2024.2.0.1\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\s056857\Desktop\algorit-duom-strukt\algoritmai-duomenu-strukturos\praktine-paskaita-sarasai

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\s056857\Desktop\algorit-duom-strukt\algoritmai-duomenu-strukturos\praktine-paskaita-sarasai\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/praktine_paskaita_sarasai.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/praktine_paskaita_sarasai.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/praktine_paskaita_sarasai.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/praktine_paskaita_sarasai.dir/flags.make

CMakeFiles/praktine_paskaita_sarasai.dir/main.cpp.obj: CMakeFiles/praktine_paskaita_sarasai.dir/flags.make
CMakeFiles/praktine_paskaita_sarasai.dir/main.cpp.obj: C:/Users/s056857/Desktop/algorit-duom-strukt/algoritmai-duomenu-strukturos/praktine-paskaita-sarasai/main.cpp
CMakeFiles/praktine_paskaita_sarasai.dir/main.cpp.obj: CMakeFiles/praktine_paskaita_sarasai.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\s056857\Desktop\algorit-duom-strukt\algoritmai-duomenu-strukturos\praktine-paskaita-sarasai\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/praktine_paskaita_sarasai.dir/main.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/praktine_paskaita_sarasai.dir/main.cpp.obj -MF CMakeFiles\praktine_paskaita_sarasai.dir\main.cpp.obj.d -o CMakeFiles\praktine_paskaita_sarasai.dir\main.cpp.obj -c C:\Users\s056857\Desktop\algorit-duom-strukt\algoritmai-duomenu-strukturos\praktine-paskaita-sarasai\main.cpp

CMakeFiles/praktine_paskaita_sarasai.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/praktine_paskaita_sarasai.dir/main.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\s056857\Desktop\algorit-duom-strukt\algoritmai-duomenu-strukturos\praktine-paskaita-sarasai\main.cpp > CMakeFiles\praktine_paskaita_sarasai.dir\main.cpp.i

CMakeFiles/praktine_paskaita_sarasai.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/praktine_paskaita_sarasai.dir/main.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\s056857\Desktop\algorit-duom-strukt\algoritmai-duomenu-strukturos\praktine-paskaita-sarasai\main.cpp -o CMakeFiles\praktine_paskaita_sarasai.dir\main.cpp.s

# Object files for target praktine_paskaita_sarasai
praktine_paskaita_sarasai_OBJECTS = \
"CMakeFiles/praktine_paskaita_sarasai.dir/main.cpp.obj"

# External object files for target praktine_paskaita_sarasai
praktine_paskaita_sarasai_EXTERNAL_OBJECTS =

praktine_paskaita_sarasai.exe: CMakeFiles/praktine_paskaita_sarasai.dir/main.cpp.obj
praktine_paskaita_sarasai.exe: CMakeFiles/praktine_paskaita_sarasai.dir/build.make
praktine_paskaita_sarasai.exe: CMakeFiles/praktine_paskaita_sarasai.dir/linkLibs.rsp
praktine_paskaita_sarasai.exe: CMakeFiles/praktine_paskaita_sarasai.dir/objects1.rsp
praktine_paskaita_sarasai.exe: CMakeFiles/praktine_paskaita_sarasai.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\s056857\Desktop\algorit-duom-strukt\algoritmai-duomenu-strukturos\praktine-paskaita-sarasai\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable praktine_paskaita_sarasai.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\praktine_paskaita_sarasai.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/praktine_paskaita_sarasai.dir/build: praktine_paskaita_sarasai.exe
.PHONY : CMakeFiles/praktine_paskaita_sarasai.dir/build

CMakeFiles/praktine_paskaita_sarasai.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\praktine_paskaita_sarasai.dir\cmake_clean.cmake
.PHONY : CMakeFiles/praktine_paskaita_sarasai.dir/clean

CMakeFiles/praktine_paskaita_sarasai.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\s056857\Desktop\algorit-duom-strukt\algoritmai-duomenu-strukturos\praktine-paskaita-sarasai C:\Users\s056857\Desktop\algorit-duom-strukt\algoritmai-duomenu-strukturos\praktine-paskaita-sarasai C:\Users\s056857\Desktop\algorit-duom-strukt\algoritmai-duomenu-strukturos\praktine-paskaita-sarasai\cmake-build-debug C:\Users\s056857\Desktop\algorit-duom-strukt\algoritmai-duomenu-strukturos\praktine-paskaita-sarasai\cmake-build-debug C:\Users\s056857\Desktop\algorit-duom-strukt\algoritmai-duomenu-strukturos\praktine-paskaita-sarasai\cmake-build-debug\CMakeFiles\praktine_paskaita_sarasai.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/praktine_paskaita_sarasai.dir/depend

