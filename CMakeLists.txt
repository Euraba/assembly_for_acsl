cmake_minimum_required(VERSION 3.17)
project(assembly)

set(CMAKE_CXX_STANDARD 14)

add_executable(assembly main.cpp program.h assemblyLine.h assembly.h)