cmake_minimum_required(VERSION 3.19)

set(CMAKE_CXX_STANDARD 20)

#configure_file(../../input_data.txt ${CMAKE_BINARY_DIR}/day5/part1/cpp/input_data.txt)
add_executable(smart_ptr main.cpp uniqur_ptr_holder.cpp unique_ptr_owner.h)