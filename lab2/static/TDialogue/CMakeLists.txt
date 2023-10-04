project(TDialogue)

add_library(TDialogue STATIC source/TDialogue.cpp)
target_include_directories(TDialogue PUBLIC include)

target_link_libraries(TDialogue RDialogue 
                                Resource
                                Handlers
                                Table)