cmake_minimum_required(VERSION 3.25)

set(This RayTracer)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib/googletest)

set(Headers
    src/Tuple.h
    src/Color.h
    src/Vector.h
)

set(Sources
    src/Tuple.cpp
    src/Color.h
    src/Vector.h
)

add_library(${This} STATIC ${Sources} ${Headers})