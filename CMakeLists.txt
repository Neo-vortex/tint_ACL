cmake_minimum_required(VERSION 3.21)
project(Auth)
set(CMAKE_CXX_STANDARD 23)

file(GLOB SOURCES
        include/*.h
        lib/*.cpp
        )
include_directories(include)
add_executable(
        Auth
        main.cpp
        ${SOURCES})
