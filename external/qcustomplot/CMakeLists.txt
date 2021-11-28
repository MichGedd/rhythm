# This file handles building each task as sub-project.
#
# Each task becomes an independent project in which you can experiment.
#
# Tasks are added as separate sub-projects so as compilation errors in
# one task don't affect another task.

cmake_minimum_required(VERSION 3.17)
project(qcustomplot)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_FLAGS -w)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5PrintSupport REQUIRED)

add_library(qcustomplot STATIC src/qcustomplot.cpp include/qcustomplot.h)
include_directories(qcustomplot include)

target_link_libraries(qcustomplot Qt5::Widgets Qt5::PrintSupport)