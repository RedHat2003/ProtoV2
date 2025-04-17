cmake_minimum_required(VERSION 3.15)
# Hat module library
file(GLOB HAT_SOURCES *.c)
add_library(hat STATIC ${HAT_SOURCES})
target_include_directories(hat PUBLIC
    ${PROJECT_SOURCE_DIR}/Include
    ${PROJECT_SOURCE_DIR}
)
target_compile_features(hat PRIVATE c_std_11)
