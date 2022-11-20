cmake_minimum_required(VERSION 3.23)
project(ProjetCDictionnary C)

set(CMAKE_C_STANDARD 11)

add_executable(ProjetCDictionnary
        main.c structures.c menus.c menus.h handleTrees.c handleTrees.h handleSentences.c handleSentences.h)
