cmake_minimum_required(VERSION 3.10)

set (CMAKE_CXX_STANDARD 11)

# set the project name
project(graphs)

# add the executable
add_library(graphs lib/ir/graph.cpp)
include_directories(include)
