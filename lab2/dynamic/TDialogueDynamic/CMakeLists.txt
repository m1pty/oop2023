project(TDialogueDynamic)

add_library(TDialogueDynamic STATIC source/TDialogue.cpp)
target_include_directories(TDialogueDynamic PUBLIC include)

include_directories(../HandlersDynamic)
link_directories(../HandlersDynamic)

include_directories(../ResourceDynamic)
link_directories(../ResourceDynamic)

include_directories(../RDialogueDynamic)
link_directories(../RDialogueDynamic)

include_directories(../TableDynamic)
link_directories(../TableDynamic)

target_link_libraries(TDialogueDynamic RDialogueDynamic 
                                       ResourceDynamic
                                       HandlersDynamic
                                       TableDynamic)