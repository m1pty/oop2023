cmake_minimum_required(VERSION 3.16)
project(Handlers)
set(CMAKE_CXX_STANDARD 17)

add_library(Handlers STATIC source/Handlers.cpp include/Handlers/Handlers.h)
target_include_directories(Handlers PUBLIC include)