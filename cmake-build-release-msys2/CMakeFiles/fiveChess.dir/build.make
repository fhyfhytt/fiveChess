# CMAKE generated file: DO NOT EDIT!
# Generated by "MSYS Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = "/D/c++/CLion 2022.1.3/bin/cmake/win/bin/cmake.exe"

# The command to remove a file.
RM = "/D/c++/CLion 2022.1.3/bin/cmake/win/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /D/work/c++/server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /D/work/c++/server/cmake-build-release-msys2

# Include any dependencies generated for this target.
include CMakeFiles/fiveChess.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/fiveChess.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/fiveChess.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fiveChess.dir/flags.make

CMakeFiles/fiveChess.dir/fiveChess_autogen/mocs_compilation.cpp.obj: CMakeFiles/fiveChess.dir/flags.make
CMakeFiles/fiveChess.dir/fiveChess_autogen/mocs_compilation.cpp.obj: CMakeFiles/fiveChess.dir/includes_CXX.rsp
CMakeFiles/fiveChess.dir/fiveChess_autogen/mocs_compilation.cpp.obj: fiveChess_autogen/mocs_compilation.cpp
CMakeFiles/fiveChess.dir/fiveChess_autogen/mocs_compilation.cpp.obj: CMakeFiles/fiveChess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/D/work/c++/server/cmake-build-release-msys2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/fiveChess.dir/fiveChess_autogen/mocs_compilation.cpp.obj"
	/E/sys2/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/fiveChess.dir/fiveChess_autogen/mocs_compilation.cpp.obj -MF CMakeFiles/fiveChess.dir/fiveChess_autogen/mocs_compilation.cpp.obj.d -o CMakeFiles/fiveChess.dir/fiveChess_autogen/mocs_compilation.cpp.obj -c /D/work/c++/server/cmake-build-release-msys2/fiveChess_autogen/mocs_compilation.cpp

CMakeFiles/fiveChess.dir/fiveChess_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fiveChess.dir/fiveChess_autogen/mocs_compilation.cpp.i"
	/E/sys2/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /D/work/c++/server/cmake-build-release-msys2/fiveChess_autogen/mocs_compilation.cpp > CMakeFiles/fiveChess.dir/fiveChess_autogen/mocs_compilation.cpp.i

CMakeFiles/fiveChess.dir/fiveChess_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fiveChess.dir/fiveChess_autogen/mocs_compilation.cpp.s"
	/E/sys2/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /D/work/c++/server/cmake-build-release-msys2/fiveChess_autogen/mocs_compilation.cpp -o CMakeFiles/fiveChess.dir/fiveChess_autogen/mocs_compilation.cpp.s

CMakeFiles/fiveChess.dir/src/main.cpp.obj: CMakeFiles/fiveChess.dir/flags.make
CMakeFiles/fiveChess.dir/src/main.cpp.obj: CMakeFiles/fiveChess.dir/includes_CXX.rsp
CMakeFiles/fiveChess.dir/src/main.cpp.obj: ../src/main.cpp
CMakeFiles/fiveChess.dir/src/main.cpp.obj: CMakeFiles/fiveChess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/D/work/c++/server/cmake-build-release-msys2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/fiveChess.dir/src/main.cpp.obj"
	/E/sys2/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/fiveChess.dir/src/main.cpp.obj -MF CMakeFiles/fiveChess.dir/src/main.cpp.obj.d -o CMakeFiles/fiveChess.dir/src/main.cpp.obj -c /D/work/c++/server/src/main.cpp

CMakeFiles/fiveChess.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fiveChess.dir/src/main.cpp.i"
	/E/sys2/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /D/work/c++/server/src/main.cpp > CMakeFiles/fiveChess.dir/src/main.cpp.i

CMakeFiles/fiveChess.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fiveChess.dir/src/main.cpp.s"
	/E/sys2/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /D/work/c++/server/src/main.cpp -o CMakeFiles/fiveChess.dir/src/main.cpp.s

CMakeFiles/fiveChess.dir/src/ChessBoard.cpp.obj: CMakeFiles/fiveChess.dir/flags.make
CMakeFiles/fiveChess.dir/src/ChessBoard.cpp.obj: CMakeFiles/fiveChess.dir/includes_CXX.rsp
CMakeFiles/fiveChess.dir/src/ChessBoard.cpp.obj: ../src/ChessBoard.cpp
CMakeFiles/fiveChess.dir/src/ChessBoard.cpp.obj: CMakeFiles/fiveChess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/D/work/c++/server/cmake-build-release-msys2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/fiveChess.dir/src/ChessBoard.cpp.obj"
	/E/sys2/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/fiveChess.dir/src/ChessBoard.cpp.obj -MF CMakeFiles/fiveChess.dir/src/ChessBoard.cpp.obj.d -o CMakeFiles/fiveChess.dir/src/ChessBoard.cpp.obj -c /D/work/c++/server/src/ChessBoard.cpp

CMakeFiles/fiveChess.dir/src/ChessBoard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fiveChess.dir/src/ChessBoard.cpp.i"
	/E/sys2/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /D/work/c++/server/src/ChessBoard.cpp > CMakeFiles/fiveChess.dir/src/ChessBoard.cpp.i

CMakeFiles/fiveChess.dir/src/ChessBoard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fiveChess.dir/src/ChessBoard.cpp.s"
	/E/sys2/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /D/work/c++/server/src/ChessBoard.cpp -o CMakeFiles/fiveChess.dir/src/ChessBoard.cpp.s

CMakeFiles/fiveChess.dir/src/MyMainWindow.cpp.obj: CMakeFiles/fiveChess.dir/flags.make
CMakeFiles/fiveChess.dir/src/MyMainWindow.cpp.obj: CMakeFiles/fiveChess.dir/includes_CXX.rsp
CMakeFiles/fiveChess.dir/src/MyMainWindow.cpp.obj: ../src/MyMainWindow.cpp
CMakeFiles/fiveChess.dir/src/MyMainWindow.cpp.obj: CMakeFiles/fiveChess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/D/work/c++/server/cmake-build-release-msys2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/fiveChess.dir/src/MyMainWindow.cpp.obj"
	/E/sys2/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/fiveChess.dir/src/MyMainWindow.cpp.obj -MF CMakeFiles/fiveChess.dir/src/MyMainWindow.cpp.obj.d -o CMakeFiles/fiveChess.dir/src/MyMainWindow.cpp.obj -c /D/work/c++/server/src/MyMainWindow.cpp

CMakeFiles/fiveChess.dir/src/MyMainWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fiveChess.dir/src/MyMainWindow.cpp.i"
	/E/sys2/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /D/work/c++/server/src/MyMainWindow.cpp > CMakeFiles/fiveChess.dir/src/MyMainWindow.cpp.i

CMakeFiles/fiveChess.dir/src/MyMainWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fiveChess.dir/src/MyMainWindow.cpp.s"
	/E/sys2/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /D/work/c++/server/src/MyMainWindow.cpp -o CMakeFiles/fiveChess.dir/src/MyMainWindow.cpp.s

CMakeFiles/fiveChess.dir/src/player.cpp.obj: CMakeFiles/fiveChess.dir/flags.make
CMakeFiles/fiveChess.dir/src/player.cpp.obj: CMakeFiles/fiveChess.dir/includes_CXX.rsp
CMakeFiles/fiveChess.dir/src/player.cpp.obj: ../src/player.cpp
CMakeFiles/fiveChess.dir/src/player.cpp.obj: CMakeFiles/fiveChess.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/D/work/c++/server/cmake-build-release-msys2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/fiveChess.dir/src/player.cpp.obj"
	/E/sys2/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/fiveChess.dir/src/player.cpp.obj -MF CMakeFiles/fiveChess.dir/src/player.cpp.obj.d -o CMakeFiles/fiveChess.dir/src/player.cpp.obj -c /D/work/c++/server/src/player.cpp

CMakeFiles/fiveChess.dir/src/player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fiveChess.dir/src/player.cpp.i"
	/E/sys2/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /D/work/c++/server/src/player.cpp > CMakeFiles/fiveChess.dir/src/player.cpp.i

CMakeFiles/fiveChess.dir/src/player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fiveChess.dir/src/player.cpp.s"
	/E/sys2/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /D/work/c++/server/src/player.cpp -o CMakeFiles/fiveChess.dir/src/player.cpp.s

# Object files for target fiveChess
fiveChess_OBJECTS = \
"CMakeFiles/fiveChess.dir/fiveChess_autogen/mocs_compilation.cpp.obj" \
"CMakeFiles/fiveChess.dir/src/main.cpp.obj" \
"CMakeFiles/fiveChess.dir/src/ChessBoard.cpp.obj" \
"CMakeFiles/fiveChess.dir/src/MyMainWindow.cpp.obj" \
"CMakeFiles/fiveChess.dir/src/player.cpp.obj"

# External object files for target fiveChess
fiveChess_EXTERNAL_OBJECTS =

../bin/fiveChess.exe: CMakeFiles/fiveChess.dir/fiveChess_autogen/mocs_compilation.cpp.obj
../bin/fiveChess.exe: CMakeFiles/fiveChess.dir/src/main.cpp.obj
../bin/fiveChess.exe: CMakeFiles/fiveChess.dir/src/ChessBoard.cpp.obj
../bin/fiveChess.exe: CMakeFiles/fiveChess.dir/src/MyMainWindow.cpp.obj
../bin/fiveChess.exe: CMakeFiles/fiveChess.dir/src/player.cpp.obj
../bin/fiveChess.exe: CMakeFiles/fiveChess.dir/build.make
../bin/fiveChess.exe: E:/sys2/mingw64/lib/libQt5Widgets.dll.a
../bin/fiveChess.exe: E:/sys2/mingw64/lib/libQt5Gui.dll.a
../bin/fiveChess.exe: E:/sys2/mingw64/lib/libQt5Core.dll.a
../bin/fiveChess.exe: CMakeFiles/fiveChess.dir/linklibs.rsp
../bin/fiveChess.exe: CMakeFiles/fiveChess.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/D/work/c++/server/cmake-build-release-msys2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable ../bin/fiveChess.exe"
	"/D/c++/CLion 2022.1.3/bin/cmake/win/bin/cmake.exe" -E rm -f CMakeFiles/fiveChess.dir/objects.a
	/E/sys2/mingw64/bin/ar.exe qc CMakeFiles/fiveChess.dir/objects.a @CMakeFiles/fiveChess.dir/objects1.rsp
	/E/sys2/mingw64/bin/g++.exe -g -Wl,--whole-archive CMakeFiles/fiveChess.dir/objects.a -Wl,--no-whole-archive -o ../bin/fiveChess.exe -Wl,--out-implib,libfiveChess.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/fiveChess.dir/linklibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/fiveChess.dir/build: ../bin/fiveChess.exe
.PHONY : CMakeFiles/fiveChess.dir/build

CMakeFiles/fiveChess.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fiveChess.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fiveChess.dir/clean

CMakeFiles/fiveChess.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MSYS Makefiles" /D/work/c++/server /D/work/c++/server /D/work/c++/server/cmake-build-release-msys2 /D/work/c++/server/cmake-build-release-msys2 /D/work/c++/server/cmake-build-release-msys2/CMakeFiles/fiveChess.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fiveChess.dir/depend
