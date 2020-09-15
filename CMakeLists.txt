cmake_minimum_required(VERSION 3.1.3)
message("M E S S A G E  > Hello there...")

set(CMAKE_OSX_SYSROOT "")

project(
    graphics-engine
    VERSION 1.0.0
    LANGUAGES C
)

# set(CMAKE_VERBOSE_MAKEFILE True)

enable_testing()

add_subdirectory(src)