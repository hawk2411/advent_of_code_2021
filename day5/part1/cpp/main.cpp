#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <memory>
#include <map>


void calc_points(const std::string &inputText, std::map<std::pair<int, int>, unsigned int> &points);

std::pair<int, int> get_point(const std::string &basicString, unsigned long start_pos, unsigned long comma_pos);

void calc_points(const std::pair<int, int> &p1, const std::pair<int, int> &p2,
                 std::map<std::pair<int, int>, unsigned int> &points);

void calc_points(const std::string &inputText, std::map<std::pair<int, int>, unsigned int> &points) {

    auto npos = inputText.find(',', 0);
    if(npos != std::string::npos) {

        std::pair<int, int> point1 = get_point( inputText, 0, npos );

        npos = inputText.find( ',', npos+1);
        std::pair<int, int> point2 = get_point( inputText, inputText.find('>')+1,npos);
        calc_points(point1, point2, points);
    }


}

void calc_points(const std::pair<int, int> &p1, const std::pair<int, int> &p2,
                 std::map<std::pair<int, int>, unsigned int> &points) {

    if(p1.first != p2.first && p1.second != p2.second) {
        return;
    }

    if(p1.first == p2.first) {
        int until = std::max(p1.second, p2.second);
        int from = std::min(p1.second, p2.second);

        for(int i = from; i <= until; i++) {
            auto p = std::pair<int, int>(p1.first, i);
            auto it = points.find(p);
            if(it == points.end()) {
                points.insert({p, 0});
            }
            else {
                it->second++;
            }


        }
    }
}

std::pair<int, int> get_point(const std::string &basicString, unsigned long start_pos, unsigned long comma_pos) {

    auto first =basicString.substr(start_pos, comma_pos - start_pos);
    auto end_digget_pos = basicString.find(' ', comma_pos);
    auto second = basicString.substr(comma_pos+1, end_digget_pos - (comma_pos+1));

    return {std::stoi(first), std::stoi(second) };
}

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

