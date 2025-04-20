file(GLOB TEST_SOURCES "*.c")

add_executable(test_core ${TEST_SOURCES})
target_include_directories(test_core PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(test_core PRIVATE object_lib)

add_test(NAME core_test COMMAND test_core)