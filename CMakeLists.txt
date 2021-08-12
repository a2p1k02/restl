cmake_minimum_required(VERSION 3.0)

set(PROJECT_NAME restl)
set(PROJECT_HEADER src/restl/astring.hpp src/restl/vector.hpp)
set(PROJECT_FILES ${PROJECT_HEADER} src/main.cpp)

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} ${PROJECT_FILES})
