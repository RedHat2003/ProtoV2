cmake_minimum_required(VERSION 3.15)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(ProtoV2 LANGUAGES C)

# Enforce C11 and strict warnings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic")

# Where to put built executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Subdirectories
add_subdirectory(hat)
add_subdirectory(object)
add_subdirectory(src)

# Enable CTest for any tests you add later
enable_testing()

