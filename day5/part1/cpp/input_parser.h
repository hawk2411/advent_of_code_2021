//
// Created by hawk on 18.06.22.
//

#ifndef ADVENT_OF_CODE_INPUT_PARSER_H
#define ADVENT_OF_CODE_INPUT_PARSER_H


#include <utility>
#include <string>

#include "point.h"

class input_parser {

public:
    static std::optional<std::pair<point, point>> get_vector_from_string(const std::string &line);
    static std::vector<point> get_points_from_vector(const std::pair<point,point>& vector_2d);
};


#endif //ADVENT_OF_CODE_INPUT_PARSER_H
