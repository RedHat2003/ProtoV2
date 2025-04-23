add_executable(test_core test_core.c)
target_include_directories(test_core PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(test_core PRIVATE object_lib)

add_executable(test2 test2.c)
target_include_directories(test2 PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(test2 PRIVATE object_lib)

add_test(NAME core_test COMMAND test_core)
add_test(NAME test2_core COMMAND test2)

