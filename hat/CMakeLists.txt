cmake_minimum_required(VERSION 3.15)

# Recursively collect all .c source files under hat/
file(GLOB_RECURSE HAT_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.c
)

# Build the static library
add_library(hat STATIC ${HAT_SOURCES})

# Include paths for headers
target_include_directories(hat PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}
)

# Enforce C11 standard
target_compile_features(hat PRIVATE c_std_11)

