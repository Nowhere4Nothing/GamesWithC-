cmake_minimum_required(VERSION 3.26)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp)

add_executable(WindowMain O&X/Program.cpp
        O&X/Window.h
        O&X/Window.cpp)


add_executable(PingPong WIN32 PingPong/Game2.cpp
        PingPong/Game2.h
        PingPong/Render.cpp
        PingPong/SimulateTheGame.cpp)
add_executable(Ast GameAsteriods/Gameplay.cpp
        GameAsteriods/ScreenRender.cpp
        GameAsteriods/AsteriodGameScreen.cpp)
add_executable(Pointer HackkerRank/Pointer.cpp)
add_executable(Array HackkerRank/Array.cpp
        HackkerRank/FoorLoop.cpp)
add_executable(ForLoop HackkerRank/FoorLoop.cpp)
