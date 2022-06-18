//
// Created by hawk on 18.06.22.
//
#include <iostream>
#include <regex>
#include "input_parser.h"

std::optional<std::pair<point, point>> input_parser::get_vector_from_string(const std::string &line) {

    std::smatch matches;
    std::regex reg( R"((\d+),(\d+)\s*->\s*(\d+),(\d+))" );

    if(!std::regex_match(line, matches, reg))
        return std::nullopt;

    unsigned int x1 = std::atoi(matches.str(1).c_str());
    unsigned int y1 = std::atoi(matches.str(2).c_str());

    unsigned int x2 = std::atoi(matches.str(3).c_str());
    unsigned int y2 = std::atoi(matches.str(4).c_str());

    if(x1 == x2 || y1 == y2)
        return std::make_pair(point(x1,y1), point(x2,y2));
    else
        return std::nullopt;
}

std::vector<point> input_parser::get_points_from_vector(const std::pair<point, point>& vector_2d) {
    std::vector<point> result;
    if( vector_2d.first.getX() == vector_2d.second.getX() )
    {
        auto max_y = std::max(vector_2d.first.getY(), vector_2d.second.getY());
        auto min_y = std::min(vector_2d.first.getY(), vector_2d.second.getY());

        for(auto y = min_y; y <= max_y; y++) {
            result.emplace_back(vector_2d.first.getX(), y);
        }
    } else {
        auto max_x = std::max(vector_2d.first.getX(), vector_2d.second.getX());
        auto min_x = std::min(vector_2d.first.getX(), vector_2d.second.getX());

        for(auto x = min_x; x <= max_x; x++) {
            result.emplace_back(x, vector_2d.first.getY());
        }

    }
    return result;
}

