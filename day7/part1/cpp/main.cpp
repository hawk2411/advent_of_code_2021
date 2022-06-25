#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <memory>
#include <map>
#include "input_parser.h"


int main() {

    const std::string input_file = "./input_data.txt";
    std::ifstream input_data(input_file);
    if(!input_data.is_open()) {
        std::cerr << "cannot find file " << input_file << std::endl;
        return 1;
    }
    unsigned int more_then_one = 0;

    std::string text_line;

    while(std::getline(input_data, text_line)) {
        auto from_to_points = input_parser::get_vector_from_string(text_line);
        if(! from_to_points.has_value()) {
            continue;
        }

        auto ps = input_parser::get_points_from_vector(from_to_points.value());
        for(const auto& pt: ps) {
            auto find_res = points.find(pt);
            if(find_res == points.end()) {
                points.insert(std::make_pair(pt, 0));
            } else{
                find_res->second++;
            }
        }
    }

    input_data.close();

    unsigned int sum = 0;
    for(const auto& [point, count] : points ) {
        if(count > 0){
            sum++;
        }
    }

    std::cout << "Solution: " << sum << std::endl;
    return 1;
}

