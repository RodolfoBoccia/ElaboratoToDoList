cmake_minimum_required(VERSION 3.17)
project(ElaboratoToDoList)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(test)
set (SOURCE_FILES ToDoList.cpp ToDoList.h ToDo.h Date.cpp Date.h SetOfLists.cpp SetOfLists.h)
add_executable(ElaboratoToDoList main.cpp)
add_library (core ${SOURCE_FILES})
target_link_libraries (ElaboratoToDoList core)