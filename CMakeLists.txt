cmake_minimum_required(VERSION 3.12)
project(algorithms C)

set(CMAKE_C_STANDARD 99)

add_executable(algorithms main.c link.h lib/BinaryTree.h lib/BinaryTree.c)