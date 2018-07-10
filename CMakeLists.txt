cmake_minimum_required(VERSION 3.10)
project(Library)

set(CMAKE_CXX_STANDARD 14)

add_executable(Library main.cpp Book.cpp Book.h Library.cpp Library.h Member.cpp Member.h Date.cpp Date.h Country.cpp Country.h)