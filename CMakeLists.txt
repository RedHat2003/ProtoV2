cmake_minimum_required(VERSION 3.10)
project(CoreProject C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic")

# List your source files
set(SOURCES
    src/main.c 
    Hat/obmalloc.c
    Hat/lifecycle.c
    Hat/objimpl.c
    Hat/refcount.c
    Object/typeobject.c
    Object/intarrobj.c
    Object/floatarrobj.c
    Object/clinic/impl/intarrobj_impl.c
    Object/clinic/impl/floatarrobj_impl.c
    
)

# Create the executable target
add_executable(core ${SOURCES})

# Include from the project root instead of the Include folder.
target_include_directories(core PRIVATE ${PROJECT_SOURCE_DIR})

