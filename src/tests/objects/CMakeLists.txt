
add_executable(test_capsule capsule_test.c)

# make sure it sees your headers
target_include_directories(test_capsule
    PRIVATE
      ${PROJECT_SOURCE_DIR}/include
)

# link in whatever libraries it needs
# e.g. if it needs your object library:
target_link_libraries(test_capsule
    PRIVATE
    hat
    object_lib
)

# register it with CTest so `ctest` will run it
add_test(
    NAME capsule_test
    COMMAND test_capsule
)


