# Proj/ProtoV2/src/tests/dtype/CMakeLists.txt

# build a small test executable out of parent.c
add_executable(test_dtype_parent parent.c)

# make sure it sees your headers
target_include_directories(test_dtype_parent
    PRIVATE
      ${PROJECT_SOURCE_DIR}/include
)

# link in whatever libraries it needs
# e.g. if it needs your object library:
target_link_libraries(test_dtype_parent
    PRIVATE
    hat
    object_lib
)

# register it with CTest so `ctest` will run it
add_test(
    NAME dtype_parent_test
    COMMAND test_dtype_parent
)

