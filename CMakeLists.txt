cmake_minimum_required(VERSION 3.10)
project(SnakeGame)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
include_directories(include)
add_executable(snake
    src/main.cpp
    src/Utils.cpp
    src/Snake.cpp
    src/Board.cpp
    src/Game.cpp
)
if(UNIX)
    target_compile_options(snake PRIVATE -pthread)
endif()
