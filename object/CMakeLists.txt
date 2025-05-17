cmake_minimum_required(VERSION 3.15)
# Object module library
file(GLOB OBJECT_SOURCES
    type.c
    intarr.c
    tuple.c
    floatarr.c
    ndarray.c
    capsule.c 
)
file(GLOB CLINIC_SOURCES
    impl/*.c
)
add_subdirectory(impl/ndarray)
add_library(object_lib STATIC
    ${OBJECT_SOURCES}
    ${CLINIC_SOURCES}
    $<TARGET_OBJECTS:ndarray_impl_lib>
)
target_include_directories(object_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(object_lib PUBLIC hat)
target_compile_features(object_lib PRIVATE c_std_11)
