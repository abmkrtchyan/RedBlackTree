cmake_minimum_required(VERSION 3.0)
project(Red_Black_Tree)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
add_executable(Red_Black_Tree
        src/main.cpp
        src/RBTree.cpp)
