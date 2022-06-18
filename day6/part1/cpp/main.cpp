#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <memory>
#include <map>

#include "input_parser.h"
#include "fish_simulator.h"

int main() {

    const std::string input_file = "./input_data.txt";
    std::ifstream input_data(input_file);
    if(!input_data.is_open()) {
        std::cerr << "cannot find file " << input_file << std::endl;
        return 1;
    }
    unsigned int more_then_one = 0;

    std::string text_line;

    unsigned int sum = 0;

    while(std::getline(input_data, text_line)) {
        auto fish_timers = input_parser::parse_line(text_line);
        fish_simulator simulator(fish_timers);
        sum = simulator.simulate(80);

    }

    input_data.close();


    std::cout << "Solution: " << sum << std::endl;
    return 1;
}

