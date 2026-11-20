cmake_minimum_required(VERSION 3.27)
project(Neurone C)

set(CMAKE_C_STANDARD 11)

add_executable(Neurone main.c
        Neurone.c
        Neurone.h
        couche.c
        couche.h
        reseau.c
        reseau.h
        liste.c
        liste.h
)
