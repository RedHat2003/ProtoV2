add_executable(test_core test_core.c)
target_include_directories(test_core PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(test_core PRIVATE object_lib)

add_executable(freelist_test freelist_test.c)
target_include_directories(freelist_test PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(freelist_test PRIVATE object_lib)

add_executable(newarray_test newarray_test.c)
target_include_directories(newarray_test PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(newarray_test PRIVATE object_lib)

add_test(NAME core_test COMMAND test_core)
add_test(NAME freelist_test_core COMMAND freelist_test)
add_test(NAME newarray_test_core COMMAND newarray_test)

