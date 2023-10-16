project(RDialogueDynamic)

add_library(RDialogueDynamic STATIC source/RDialogue.cpp)
target_include_directories(RDialogueDynamic PUBLIC include)

include_directories(../HandlersDynamic)
link_directories(../HandlersDynamic)

include_directories(../ResourceDynamic)
link_directories(../ResourceDynamic)

target_link_libraries(RDialogueDynamic ResourceDynamic
                                       HandlersDynamic)