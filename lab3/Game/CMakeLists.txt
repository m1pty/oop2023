project(Game)
set(CMAKE_CXX_STANDARD 20)

add_library(Game STATIC source/Game.cpp)
target_include_directories(Game PUBLIC include)