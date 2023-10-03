cmake_minimum_required(VERSION 3.16)
project(Table)
set(CMAKE_CXX_STANDARD 17)

add_library(Table STATIC source/Table.cpp)
target_include_directories(Table PUBLIC include)
target_link_libraries(Table Resource Handlers RDialogue)