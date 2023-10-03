cmake_minimum_required(VERSION 3.16)
project(Resource)
set(CMAKE_CXX_STANDARD 17)

add_library(Resource STATIC source/Resource.cpp)
target_include_directories(Resource PUBLIC include)
target_link_libraries(Resource Handlers)