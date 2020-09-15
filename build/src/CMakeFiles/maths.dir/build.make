# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.18.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.18.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/build

# Include any dependencies generated for this target.
include src/CMakeFiles/maths.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/maths.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/maths.dir/flags.make

src/CMakeFiles/maths.dir/maths/vec2.c.o: src/CMakeFiles/maths.dir/flags.make
src/CMakeFiles/maths.dir/maths/vec2.c.o: ../src/maths/vec2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/maths.dir/maths/vec2.c.o"
	cd /Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/maths.dir/maths/vec2.c.o -c /Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/src/maths/vec2.c

src/CMakeFiles/maths.dir/maths/vec2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/maths.dir/maths/vec2.c.i"
	cd /Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/src/maths/vec2.c > CMakeFiles/maths.dir/maths/vec2.c.i

src/CMakeFiles/maths.dir/maths/vec2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/maths.dir/maths/vec2.c.s"
	cd /Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/src/maths/vec2.c -o CMakeFiles/maths.dir/maths/vec2.c.s

src/CMakeFiles/maths.dir/maths/vec3.c.o: src/CMakeFiles/maths.dir/flags.make
src/CMakeFiles/maths.dir/maths/vec3.c.o: ../src/maths/vec3.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/CMakeFiles/maths.dir/maths/vec3.c.o"
	cd /Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/maths.dir/maths/vec3.c.o -c /Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/src/maths/vec3.c

src/CMakeFiles/maths.dir/maths/vec3.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/maths.dir/maths/vec3.c.i"
	cd /Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/src/maths/vec3.c > CMakeFiles/maths.dir/maths/vec3.c.i

src/CMakeFiles/maths.dir/maths/vec3.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/maths.dir/maths/vec3.c.s"
	cd /Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/src/maths/vec3.c -o CMakeFiles/maths.dir/maths/vec3.c.s

src/CMakeFiles/maths.dir/maths/vec4.c.o: src/CMakeFiles/maths.dir/flags.make
src/CMakeFiles/maths.dir/maths/vec4.c.o: ../src/maths/vec4.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/CMakeFiles/maths.dir/maths/vec4.c.o"
	cd /Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/maths.dir/maths/vec4.c.o -c /Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/src/maths/vec4.c

src/CMakeFiles/maths.dir/maths/vec4.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/maths.dir/maths/vec4.c.i"
	cd /Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/src/maths/vec4.c > CMakeFiles/maths.dir/maths/vec4.c.i

src/CMakeFiles/maths.dir/maths/vec4.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/maths.dir/maths/vec4.c.s"
	cd /Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/src/maths/vec4.c -o CMakeFiles/maths.dir/maths/vec4.c.s

src/CMakeFiles/maths.dir/maths/mat4.c.o: src/CMakeFiles/maths.dir/flags.make
src/CMakeFiles/maths.dir/maths/mat4.c.o: ../src/maths/mat4.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object src/CMakeFiles/maths.dir/maths/mat4.c.o"
	cd /Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/maths.dir/maths/mat4.c.o -c /Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/src/maths/mat4.c

src/CMakeFiles/maths.dir/maths/mat4.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/maths.dir/maths/mat4.c.i"
	cd /Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/src/maths/mat4.c > CMakeFiles/maths.dir/maths/mat4.c.i

src/CMakeFiles/maths.dir/maths/mat4.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/maths.dir/maths/mat4.c.s"
	cd /Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/src/maths/mat4.c -o CMakeFiles/maths.dir/maths/mat4.c.s

src/CMakeFiles/maths.dir/maths/helper.c.o: src/CMakeFiles/maths.dir/flags.make
src/CMakeFiles/maths.dir/maths/helper.c.o: ../src/maths/helper.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object src/CMakeFiles/maths.dir/maths/helper.c.o"
	cd /Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/maths.dir/maths/helper.c.o -c /Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/src/maths/helper.c

src/CMakeFiles/maths.dir/maths/helper.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/maths.dir/maths/helper.c.i"
	cd /Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/src/maths/helper.c > CMakeFiles/maths.dir/maths/helper.c.i

src/CMakeFiles/maths.dir/maths/helper.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/maths.dir/maths/helper.c.s"
	cd /Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/build/src && /usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/src/maths/helper.c -o CMakeFiles/maths.dir/maths/helper.c.s

# Object files for target maths
maths_OBJECTS = \
"CMakeFiles/maths.dir/maths/vec2.c.o" \
"CMakeFiles/maths.dir/maths/vec3.c.o" \
"CMakeFiles/maths.dir/maths/vec4.c.o" \
"CMakeFiles/maths.dir/maths/mat4.c.o" \
"CMakeFiles/maths.dir/maths/helper.c.o"

# External object files for target maths
maths_EXTERNAL_OBJECTS =

src/libmaths.a: src/CMakeFiles/maths.dir/maths/vec2.c.o
src/libmaths.a: src/CMakeFiles/maths.dir/maths/vec3.c.o
src/libmaths.a: src/CMakeFiles/maths.dir/maths/vec4.c.o
src/libmaths.a: src/CMakeFiles/maths.dir/maths/mat4.c.o
src/libmaths.a: src/CMakeFiles/maths.dir/maths/helper.c.o
src/libmaths.a: src/CMakeFiles/maths.dir/build.make
src/libmaths.a: src/CMakeFiles/maths.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C static library libmaths.a"
	cd /Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/build/src && $(CMAKE_COMMAND) -P CMakeFiles/maths.dir/cmake_clean_target.cmake
	cd /Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/maths.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/maths.dir/build: src/libmaths.a

.PHONY : src/CMakeFiles/maths.dir/build

src/CMakeFiles/maths.dir/clean:
	cd /Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/build/src && $(CMAKE_COMMAND) -P CMakeFiles/maths.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/maths.dir/clean

src/CMakeFiles/maths.dir/depend:
	cd /Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine /Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/src /Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/build /Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/build/src /Users/seanbryan/Documents/Physics/phys-programming/side-projects/graphics-engine/build/src/CMakeFiles/maths.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/maths.dir/depend
