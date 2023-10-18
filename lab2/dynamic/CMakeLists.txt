cmake_minimum_required(VERSION 3.16)
project(dynamic)
set(CMAKE_CXX_STANDARD 17) # установка стандарта языка - C++17

# установка флагов компилятора: CMAKE_CXX_FLAGS += -Wall -Wextra
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -Wextra --coverage")

# добавление директорий с библиотеками и тестами
add_subdirectory( ResourceDynamic )
add_subdirectory( HandlersDynamic )
add_subdirectory( TableDynamic )
add_subdirectory( RDialogueDynamic )
add_subdirectory( TDialogueDynamic )

# создание исполняемого файла для класса Resource
add_executable(main_rd main_r.cpp)
target_link_libraries(main_rd ResourceDynamic HandlersDynamic RDialogueDynamic)

# создание исполняемого файла для класса Table
add_executable(main_td main_t.cpp)
target_link_libraries(main_td ResourceDynamic HandlersDynamic RDialogueDynamic TableDynamic TDialogueDynamic)

add_compile_options(--coverage)
add_link_options(--coverage)

Include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.1 # or a later release
)
FetchContent_MakeAvailable(Catch2)

add_compile_options(--coverage)
add_link_options(--coverage)
add_executable(TestsDynamic TestsDynamic/source/TestCase.cpp)
target_link_libraries(TestsDynamic PUBLIC Catch2::Catch2WithMain 
                                   ResourceDynamic 
                                   HandlersDynamic 
                                   RDialogueDynamic
                                   TDialogueDynamic
                                   TableDynamic
                      )