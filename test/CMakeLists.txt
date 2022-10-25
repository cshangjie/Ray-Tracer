cmake_minimum_required(VERSION 3.25)

set(This RayTracer_Tests)

set(Sources
    TupleTests.cpp
    VectorTests.cpp
    PointTests.cpp
    ColorTests.cpp
    CanvasTests.cpp
)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC gtest_main RayTracer primitive_lib)


add_test(
    NAME ${This}
    COMMAND ${This}
)
