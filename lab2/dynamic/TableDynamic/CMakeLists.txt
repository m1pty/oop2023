cmake_minimum_required(VERSION 3.16)
project(TableDynamic)
set(CMAKE_CXX_STANDARD 17)

add_library(TableDynamic STATIC source/Table.cpp)
target_include_directories(TableDynamic PUBLIC include)
target_link_libraries(TableDynamic ResourceDynamic HandlersDynamic RDialogueDynamic)