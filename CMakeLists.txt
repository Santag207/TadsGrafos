cmake_minimum_required(VERSION 3.26)
project(untitled1)

set(CMAKE_CXX_STANDARD 11)

add_executable(untitled1 main.cpp
        "Source Files/Grafo.cpp"
        "Header Files/Grafo.h"
        "Source Files/Vertice.cpp"
        "Header Files/Vertice.h"
        "Source Files/Arista.cpp"
        "Header Files/Arista.h")
