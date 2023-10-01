cmake_minimum_required(VERSION 3.16)
project(OOPLab2)
set(CMAKE_CXX_STANDARD 17) # установка стандарта языка - C++17

# установка флагов компилятора: CMAKE_CXX_FLAGS += -Wall -Wextra
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -Wextra")

# добавление директорий с библиотеками и тестами
add_subdirectory(Resource )
add_subdirectory(Handlers )
add_subdirectory(RDialogue)

# создание исполняемого файла
add_executable(main main.cpp)
target_link_libraries(main Resource
                           Handlers
                           RDialogue
                    )

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
target_link_libraries(Tests PRIVATE Catch2::Catch2WithMain
                                    Resource
                                    Handlers
                                    RDialogue
)


# для сборки из консоли:
#
# mkdir build   # создание директории для файлов сборки
# cd build      # переход в директорию сборки
# cmake ..      # генерация файлов сборки на основе CMakeLists.txt
# make          # сборка проекта