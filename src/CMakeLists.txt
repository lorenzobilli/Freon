cmake_minimum_required(VERSION 3.12)

add_library(Persistence Persistence.cpp)
add_library(Freezable Freezable.cpp)
target_link_libraries(Freezable Persistence)