cmake_minimum_required(VERSION 3.12)

add_library(Freezer Freezer.cpp)
add_library(Defroster Defroster.cpp)
add_library(Freezable Freezable.cpp)
target_link_libraries(Freezable Freezer Defroster)