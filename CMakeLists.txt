cmake_minimum_required(VERSION 3.1)
project(shell)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(SOURCE_FILES src/main.c src/shell.c)
add_executable(shell ${SOURCE_FILES})