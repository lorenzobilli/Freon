cmake_minimum_required(VERSION 3.12)

add_library(Persistence Persistence.cpp)
add_library(PersistentObject PersistentObject.cpp)
target_link_libraries(PersistentObject Persistence)