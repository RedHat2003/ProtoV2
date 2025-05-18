add_executable(test_clinic_headers test_clinic_headers.c)

target_include_directories(test_clinic_headers PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

add_test(NAME test_clinic_headers_run COMMAND test_clinic_headers)

