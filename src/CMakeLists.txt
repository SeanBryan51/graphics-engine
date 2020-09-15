add_executable(main main.c)

# link third party libraries:

find_package(glfw3 3.3 REQUIRED)
target_link_libraries(main glfw)

find_package(GLEW REQUIRED)
target_link_libraries(main GLEW)

target_link_libraries(main "-framework Cocoa")
target_link_libraries(main "-framework OpenGL")
target_link_libraries(main "-framework IOKit")

# define custom libraries:

add_library(
    utils
    utils/fileutils.c
    utils/fileutils.h
)

target_include_directories(utils PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(main utils)

add_library(
    graphics
    graphics/graphics.h
    graphics/window.c
    graphics/shader.c
)

target_include_directories(graphics PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(main graphics)

add_library(
    maths
    maths/maths.h
    maths/vec2.c
    maths/vec3.c
    maths/vec4.c
    maths/mat4.c
    maths/helper.c
)

target_include_directories(maths PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(main maths)

# configure tests:

add_executable(test_mat4 tests/test_mat4.c)
target_link_libraries(test_mat4 maths)
add_test(test-mat4 test_mat4)

add_executable(test_vec2 tests/test_vec2.c)
target_link_libraries(test_vec2 maths)
add_test(test-vec2 test_vec2)

add_executable(test_vec3 tests/test_vec3.c)
target_link_libraries(test_vec3 maths)
add_test(test-vec3 test_vec3)

add_executable(test_vec4 tests/test_vec4.c)
target_link_libraries(test_vec4 maths)
add_test(test-vec4 test_vec4)