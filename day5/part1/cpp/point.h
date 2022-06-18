//
// Created by hawk on 18.06.22.
//

#ifndef ADVENT_OF_CODE_POINT_H
#define ADVENT_OF_CODE_POINT_H


#include <complex>

class point {
    unsigned int _x;
    unsigned int _y;

public:
    point(unsigned int x, unsigned int y) : _x(x), _y(y){}

    virtual bool operator==(const point& pt) const{
        return (pt._x == _x) && (pt._y == _y);
    }

    [[nodiscard]] double get_length() const {
        return std::sqrt(_x*_x + _y*_y);
    }

    bool operator<(const point& pt)const{

        double length_this = get_length();
        double length_pt = pt.get_length();

        if( length_this < length_pt)
            return true;

        if(length_this == length_pt) {

            if(operator==(pt)) {
                return false;
            }
            else {
                return (_x < pt._x);
            }
        }

        return false;
    }

    [[nodiscard]] unsigned int getX() const {
        return _x;
    }

    [[nodiscard]] unsigned int getY() const {
        return _y;
    }
};

class count_matches : public point {

    unsigned int _matches = 0;
public:
    count_matches(unsigned int x, unsigned y) : point(x ,y){}

    void check_point(const point& pt){
        if(operator==(pt)) {
            _matches++;
        }
    }

    [[nodiscard]] unsigned int getMatches() const {
        return _matches;
    }
};


#endif //ADVENT_OF_CODE_POINT_H
