cmake_minimum_required(VERSION 3.17)
project(rhythm)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5Widgets REQUIRED)

set(SOURCE_FILES
        "${CMAKE_SOURCE_DIR}/src/main.cpp")

add_executable(rhythm ${SOURCE_FILES})
include_directories(rhythm include)

target_link_libraries(rhythm Qt5::Widgets)