cmake_minimum_required(VERSION 3.16)
project(OOPLab2)
set(CMAKE_CXX_STANDARD 17) # установка стандарта языка - C++17

# установка флагов компилятора: CMAKE_CXX_FLAGS += -Wall -Wextra
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -Wextra --coverage")
add_subdirectory(  static )
add_subdirectory( dynamic )