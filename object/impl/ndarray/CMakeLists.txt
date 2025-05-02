# object/impl/ndarray/CMakeLists.txt

add_library(ndarray_impl_lib OBJECT
    alloc.c
    dtype.c
    descr.c
)

target_include_directories(ndarray_impl_lib PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

