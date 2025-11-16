cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Benchmarks VERSION 1.1)
set(matplot ./libs/matplotplusplus)
add_subdirectory(${matplot})

set(sourcefiles test.cpp ./src/header/sort.hpp ./src/impls/sort.cpp)


add_executable(test ${sourcefiles})
target_link_libraries(test PRIVATE ${matplot})