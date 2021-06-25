cmake_minimum_required(VERSION 3.0)

set(PROJECT_NAME restl)
set(PROJECT_HEADER src/restl/astring.h src/restl/vector.hpp src/restl/new.hpp)
set(PROJECT_SOURCE src/restl/astring.cpp)
set(PROJECT_FILES ${PROJECT_HEADER} ${PROJECT_SOURCE} src/main.cpp)

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} ${PROJECT_FILES})
