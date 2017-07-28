cmake_minimum_required(VERSION 3.5)
project(shader_1_lesson)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Shader.h Shader.cpp stb_image.cpp stb_image.hpp)
add_executable(shader_1_lesson ${SOURCE_FILES})
target_link_libraries(shader_1_lesson GL GLEW glfw)