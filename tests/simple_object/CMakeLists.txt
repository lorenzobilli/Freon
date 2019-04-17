cmake_minimum_required(VERSION 3.12)

add_executable(simple_object main.cpp Person.cpp)
target_link_libraries(simple_object Freezable)