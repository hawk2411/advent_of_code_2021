cmake_minimum_required(VERSION 3.19)

set(CMAKE_CXX_STANDARD 20)

configure_file(../../input_data.txt ${CMAKE_BINARY_DIR}/day6/part1/cpp/input_data.txt)
add_executable(day6_part1 main.cpp input_parser.cpp input_parser.h fish_simulator.cpp fish_simulator.h)

target_link_libraries(day6_part1 pthread)