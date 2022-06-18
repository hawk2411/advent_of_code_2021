#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <memory>
#include <map>
#include "point.h"
#include "input_parser.h"

//std::pair<int, int> get_point(const std::string &basicString, unsigned long start_pos, unsigned long comma_pos) {
//
//    auto first =basicString.substr(start_pos, comma_pos - start_pos);
//    auto end_digget_pos = basicString.find(' ', comma_pos);
//    auto second = basicString.substr(comma_pos+1, end_digget_pos - (comma_pos+1));
//
//    return {std::stoi(first), std::stoi(second) };
//}
//
//void calc_points(const std::pair<int, int> &p1, const std::pair<int, int> &p2,
//                 std::map<std::pair<int, int>, unsigned int> &points) {
//
//    if(p1.first != p2.first && p1.second != p2.second) {
//        return;
//    }
//
//    if(p1.first == p2.first) {
//        int until = std::max(p1.second, p2.second);
//        int from = std::min(p1.second, p2.second);
//
//        for(int i = from; i <= until; i++) {
//            auto p = std::pair<int, int>(p1.first, i);
//            auto it = points.find(p);
//            if(it == points.end()) {
//                points.insert({p, 0});
//            }
//            else {
//                it->second++;
//            }
//        }
//    }
//}

//void calc_points(const std::string &inputText, std::map<std::pair<int, int>, unsigned int> &points) {
//
//    auto npos = inputText.find(',', 0);
//    if(npos != std::string::npos) {
//
//        std::pair<int, int> point1 = get_point( inputText, 0, npos );
//
//        npos = inputText.find( ',', npos+1);
//        std::pair<int, int> point2 = get_point( inputText, inputText.find('>')+1,npos);
//        calc_points(point1, point2, points);
//    }
//
//
//}



int main() {

    const std::string input_file = "./input_data.txt";
    std::ifstream input_data(input_file);
    if(!input_data.is_open()) {
        std::cerr << "cannot find file " << input_file << std::endl;
        return 1;
    }
    unsigned int more_then_one = 0;

    std::string text_line;
    std::map<point, unsigned int> points;

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

