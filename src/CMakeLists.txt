cmake_minimum_required(VERSION 3.12)

add_library(Item Item.cpp)
add_library(Freezer Freezer.cpp)
add_library(Defroster Defroster.cpp)
add_library(freon Freezable.cpp)
target_link_libraries(freon Item Freezer Defroster)
