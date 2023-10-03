cmake_minimum_required(VERSION 3.16)
project(RDialogue)
set(CMAKE_CXX_STANDARD 17)

add_library(RDialogue STATIC source/RDialogue.cpp)
target_include_directories(RDialogue PUBLIC include)
target_link_libraries(RDialogue Resource
                                Handlers)

# add_library(TDialogue STATIC source/TDialogue.cpp)
# target_include_directories(TDialogue PUBLIC include)
# target_link_libraries(TDialogue Resource
#                                 Handlers)