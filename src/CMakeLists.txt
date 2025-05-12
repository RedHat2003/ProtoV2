cmake_minimum_required(VERSION 3.15)

# Core executable
add_executable(core main.c)

# Pull in our tests directory
add_subdirectory(tests)

# Include your headers
target_include_directories(core PRIVATE ${PROJECT_SOURCE_DIR}/include)

# ✅ Fix linker order: link hat first, then object_lib
target_link_libraries(core PRIVATE
    hat
    object_lib
)

# Enforce C11
target_compile_features(core PRIVATE c_std_11)

