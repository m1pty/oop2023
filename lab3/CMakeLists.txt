cmake_minimum_required(VERSION 3.16)
project(SummonerGame)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -Wextra")

# добавление директорий с классами

add_subdirectory( Entity   )
add_subdirectory( Game     )
add_subdirectory( Graphics )
add_subdirectory( School   )
add_subdirectory( Services )
add_subdirectory( Troop    )

add_executable(main main.cpp)
target_link_libraries(main Entity Game Graphics School Services Troop)

# Include(FetchContent)
# FetchContent_Declare(
#   Catch2
#   GIT_REPOSITORY https://github.com/catchorg/Catch2.git
#   GIT_TAG        v3.0.1 # or a later release
# )
# FetchContent_MakeAvailable(Catch2)

# add_executable(TestsDynamic TestsDynamic/source/TestCase.cpp)
# target_link_libraries(TestsDynamic PUBLIC Catch2::Catch2WithMain 
#                                    ResourceDynamic 
#                                    HandlersDynamic 
#                                    RDialogueDynamic
#                                    TDialogueDynamic
#                                    TableDynamic
#                       )
# add_compile_options(--coverage)
# add_link_options(--coverage)