cmake_minimum_required(VERSION 3.15)
project(ProtoV2 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic")
# Place all executables in the top‐level build directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Build modular components
add_subdirectory(Hat)
add_subdirectory(Object)
add_subdirectory(src)
