cmake_minimum_required(VERSION 3.17)
project(rhythm)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Qt5NetworkAuth REQUIRED)
find_package(Qt5PrintSupport REQUIRED)

set(SOURCE_FILES
        src/main.cpp src/SpotifyOAuth.cpp src/LoginPage.cpp src/Application.cpp src/HomePage.cpp src/NavBar.cpp src/CreatePlaylistPage.cpp
        src/SavedPlaylistPage.cpp include/mainwindow.h include/qcustomplot.h include/playlistAlgorithm.h)

set(HEADER_FILES
        include/Application.h include/HomePage.h include/LoginPage.h include/SpotifyOAuth.h include/NavBar.h include/CreatePlaylistPage.h
        include/SavedPlaylistPage.h src/mainwindow.cpp src/qcustomplot.cpp src/playlistAlgorithm.cpp)

add_executable(rhythm ${HEADER_FILES} ${SOURCE_FILES})
include_directories(rhythm include)

target_link_libraries(rhythm Qt5::Widgets Qt5::Network Qt5::NetworkAuth Qt5::PrintSupport)

add_custom_target(copy_resources COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/resources ${CMAKE_CURRENT_BINARY_DIR}/resources)
add_dependencies(rhythm copy_resources)
