project(TDialogue)

add_library(TDialogue STATIC source/TDialogue.cpp)
target_include_directories(TDialogue PUBLIC include)

include_directories(../Handlers)
link_directories(../Handlers)

include_directories(../Resource)
link_directories(../Resource)

link_directories(../RDialogue)
include_directories(../RDialogue)

link_directories(../Table)
include_directories(../Table)

target_link_libraries(TDialogue RDialogue 
                                Resource
                                Handlers
                                Table)