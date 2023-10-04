cmake_minimum_required(VERSION 3.16)
project(static)
set(CMAKE_CXX_STANDARD 17) # установка стандарта языка - C++17

# установка флагов компилятора: CMAKE_CXX_FLAGS += -Wall -Wextra
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -Wextra")

# добавление директорий с библиотеками и тестами
add_subdirectory( Resource )
add_subdirectory( Handlers )
add_subdirectory( Table    )
add_subdirectory( RDialogue)
add_subdirectory( TDialogue)

# создание исполняемого файла для класса Resource
add_executable(main_r main_r.cpp)
target_link_libraries(main_r Resource Handlers RDialogue)

# создание исполняемого файла для класса Table
add_executable(main_t main_t.cpp)
target_link_libraries(main_t Resource Handlers RDialogue Table TDialogue)

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
add_executable(Tests Tests/source/TestCase.cpp)
target_link_libraries(Tests PUBLIC Catch2::Catch2WithMain 
                                   Resource 
                                   Handlers 
                                   RDialogue
                                   TDialogue
                                   Table
                      )