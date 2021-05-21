cmake_minimum_required(VERSION 3.12)

add_executable(matrix main.cpp Matrix.cpp)
target_link_libraries(matrix freon)