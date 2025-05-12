# object/impl/ndarray/CMakeLists.txt

add_library(ndarray_impl_lib OBJECT
    alloc.c
    abstract.c
    dtype.c
    descr.c
    dtypemeta.c
)

target_include_directories(ndarray_impl_lib PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

