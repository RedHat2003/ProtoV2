cmake_minimum_required(VERSION 3.15)
 # Core executable
 add_executable(core main.c)
 target_include_directories(core PRIVATE ${PROJECT_SOURCE_DIR}/include)
 target_link_libraries(core PRIVATE object_lib)
 target_compile_features(core PRIVATE c_std_11)
 target_compile_features(core PRIVATE c_std_11)
