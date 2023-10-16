cmake_minimum_required(VERSION 3.16)
project(HandlersDynamic)
set(CMAKE_CXX_STANDARD 17)

add_library(HandlersDynamic STATIC source/Handlers.cpp include/HandlersDynamic/Handlers.h)
target_include_directories(HandlersDynamic PUBLIC include)