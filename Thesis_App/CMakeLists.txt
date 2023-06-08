cmake_minimum_required(VERSION 3.20)
project(Thesis_App)

set(CMAKE_CXX_STANDARD 14)

add_executable(Thesis_App main.cpp Boolean.cpp Boolean.h Karnaugh.cpp Karnaugh.h Tabulation.cpp Tabulation.h)
