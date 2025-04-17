cmake_minimum_required(VERSION 3.15)
# Object module library
file(GLOB OBJECT_SOURCES
    typeobject.c
    intarrobj.c
    tupleobj.c
    floatarrobj.c
)
file(GLOB CLINIC_SOURCES
    clinic/impl/*.c
)
add_library(object_lib STATIC ${OBJECT_SOURCES} ${CLINIC_SOURCES})
target_include_directories(object_lib PUBLIC ${PROJECT_SOURCE_DIR}/Include)
target_link_libraries(object_lib PUBLIC hat)
target_compile_features(object_lib PRIVATE c_std_11)