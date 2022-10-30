# Trabalho algoritmos
cmake_minimum_required(VERSION 3.10)
project(Trabalho_Algortimos)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(Trabalho_Algortimos main.cpp UcTurma.cpp UcTurma.h Student.cpp Student.h ClassSchedule.cpp ClassSchedule.h Manager.cpp Manager.h LoadSclasses.h LoadSchedule.h ClassOcupation.h DisplayStudentsInClassUcYear.h)