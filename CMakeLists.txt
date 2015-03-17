cmake_minimum_required(VERSION 3.1)
project(shell)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(SOURCE_FILES src/main.c src/shell.c src/interpreter.c src/list.c src/tokenizer.c src/command.c)
add_executable(shell ${SOURCE_FILES} src/process.h src/process.c)