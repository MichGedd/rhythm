cmake_minimum_required(VERSION 3.17)
project(rhythm)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_FLAGS -w)
set(CMAKE_AUTOUIC_SEARCH_PATHS ui)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Qt5NetworkAuth REQUIRED)
find_package(Qt5 COMPONENTS Concurrent REQUIRED)


add_subdirectory(external/qcustomplot)

set(SOURCE_FILES
        src/main.cpp src/SpotifyOAuth.cpp src/LoginPage.cpp src/Application.cpp src/HomePage.cpp src/NavBar.cpp
        include/CreatePlaylistPage.h include/PlaylistAlgorithm.h)

set(HEADER_FILES
        include/Application.h include/HomePage.h include/LoginPage.h include/SpotifyOAuth.h include/NavBar.h
        src/CreatePlaylistPage.cpp src/PlaylistAlgorithm.cpp)


add_executable(rhythm ${HEADER_FILES} ${SOURCE_FILES})
include_directories(rhythm include ui ${qcustomplot_SOURCE_DIR}/include)

target_link_libraries(rhythm qcustomplot Qt5::Widgets Qt5::Network  Qt5::NetworkAuth Qt5::Concurrent)

add_custom_target(copy_resources COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/resources ${CMAKE_CURRENT_BINARY_DIR}/resources)
add_dependencies(rhythm copy_resources)
