cmake_minimum_required(VERSION 3.1)
project(shell)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(SOURCE_FILES src/shell.c src/interpreter.c src/list.c src/tokenizer.c src/command.c src/builtin.c)
add_executable(shell ${SOURCE_FILES})
