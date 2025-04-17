# ProtoV2

A prototype core runtime and object system implemented in C.

## Project Structure
- `Include/` : Public headers and API definitions.
- `Hat/`     : Low-level runtime support (memory allocation, reference counting).
- `Object/`  : Object types and implementations (int/float arrays, tuples, type objects).
- `src/`     : Application entry point (`main.c`).
- `build/`   : Out-of-source build directory.

## Requirements
- CMake 3.15 or later
- C compiler with C11 support (e.g., GCC 5.0+)

## Building
```bash
# From project root
mkdir build && cd build
cmake ..
cmake --build .
```

- The `core` executable is generated in `build/`.
- Clean with:
  ```bash
  cmake --build . --target clean
  ```

## Module Overview
1. **Hat**: Memory allocation and lifecycle routines.
2. **Object**: Object model (type objects, arrays, tuples).
3. **src**: Main program entry point.

## Project Structure Commentary
The codebase uses a modular CMake hierarchy:
- Each component lives in its own subdirectory with its own CMakeLists.
- Dependencies are explicit (Object → Hat, core → Object).
- Allows parallel and incremental builds, and easy extension with new modules or tests.

Future enhancements include adding unit tests (via CTest), API docs (Doxygen), and packaging (CPack).