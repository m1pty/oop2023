project(Graphics)
set(CMAKE_CXX_STANDARD 20)

add_library(Graphics STATIC source/Graphics.cpp)
target_include_directories(Graphics PUBLIC include)