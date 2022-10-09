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
list(APPEND CMAKE_CTEST_ARGUMENTS "--output-on-failure")

add_subdirectory(${PROJECT_SOURCE_DIR}/dependencies/glfw)
add_subdirectory(${PROJECT_SOURCE_DIR}/dependencies/glew)

add_subdirectory(src)