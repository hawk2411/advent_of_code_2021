#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <memory>
#include <map>


void calc_points(const std::string &inputText, std::map<std::pair<int, int>, unsigned int> &points);

int main() {

    const std::string input_file = "./input_data.txt";
    std::ifstream input_data(input_file);
    if(!input_data.is_open()) {
        std::cerr << "cannot find file " << input_file << std::endl;
        return 1;
    }
    std::string text_line;
    std::map<std::pair<int, int>, unsigned int> points;
    while(std::getline(input_data, text_line)) {
        calc_points(text_line, points);
    }

    input_data.close();

    std::cout << "No solution found: " << std::endl;
    return 1;
}

void calc_points(const std::string &inputText, std::map<std::pair<int, int>, unsigned int> &points) {


}
