cmake_minimum_required(VERSION 3.15)

# Tell CMake to generate compile_commands.json for your IDE
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(ProtoV2 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(hat)
add_subdirectory(object)
add_subdirectory(src)

