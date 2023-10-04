project(RDialogue)

add_library(RDialogue STATIC source/RDialogue.cpp)
target_include_directories(RDialogue PUBLIC include)

include_directories(../Handlers)
link_directories(../Handlers)

include_directories(../Resource)
link_directories(../Resource)

target_link_libraries(RDialogue Resource
                                Handlers)