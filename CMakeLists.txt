cmake_minimum_required(VERSION 3.17)
project(rhythm)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        "${CMAKE_SOURCE_DIR}/src/main.cpp")

add_executable(rhythm ${SOURCE_FILES})
include_directories(rhythm include)