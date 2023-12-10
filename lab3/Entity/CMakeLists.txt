project(Entity)
set(CMAKE_CXX_STANDARD 20)

add_library(Entity STATIC source/Entity.cpp)
target_include_directories(Entity PUBLIC include)