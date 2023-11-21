cmake_minimum_required(VERSION 3.26)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp)
add_executable(Frame X&O/Start.cpp
        X&O/Window.h
        X&O/Program.cpp)
add_executable(WindowMain O&X/Program.cpp
        O&X/Window.h
        O&X/Window.cpp)
