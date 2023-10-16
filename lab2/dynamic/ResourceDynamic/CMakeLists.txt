cmake_minimum_required(VERSION 3.16)
project(ResourceDynamic)
set(CMAKE_CXX_STANDARD 17)

add_library(ResourceDynamic STATIC source/Resource.cpp)
target_include_directories(ResourceDynamic PUBLIC include)
target_link_libraries(ResourceDynamic HandlersDynamic)