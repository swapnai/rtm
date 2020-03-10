cmake_minimum_required(VERSION 3.10)

set (CMAKE_CXX_STANDARD 11)

include(cmake/gtest.cmake)

project(graph_project)

set(CMAKE_INSTALL_BINDIR "bin")
set(CMAKE_INSTALL_INCLUDEDIR "include")
set(CMAKE_INSTALL_LIBDIR "lib")

include_directories(src)

add_subdirectory(src)
add_subdirectory(test)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/
    DESTINATION ${GRAPHS_INSTALL_INCLUDE}/graphs
    FILES_MATCHING
        PATTERN "*.hpp"
        PATTERN "*.h"
)

