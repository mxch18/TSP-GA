cmake_minimum_required (VERSION 3.1)

project(TSP-GA)
set(CMAKE_CXX_STANDARD 98)

include_directories(include)
set(SOURCES src/main.cpp src/Point.cpp src/Path.cpp)

add_executable(tspga ${SOURCES})
