//
// Created by hawk on 18.06.22.
//

#ifndef ADVENT_OF_CODE_FISH_SIMULATOR_H
#define ADVENT_OF_CODE_FISH_SIMULATOR_H

#include <vector>
#include <iostream>
#include <array>

const unsigned int daysBeforeFirstBirth = 8;
const unsigned int daysBeforeNextBirth = 6;

class fish {

public:
    static std::size_t start(unsigned int days_before_first_birth, unsigned int days_to_live) {
        std::size_t result = 0;
        result = (days_to_live >= (days_before_first_birth + 1)) ? 1 : 0;
        if( result == 0) {
            return result;
        }
        auto remaining_days = days_to_live - (days_before_first_birth + 1);

        auto div = remaining_days / (daysBeforeNextBirth + 1);
        if( div < 1 ) {
            return result;
        }
        result += div;

        result += fish::start(daysBeforeFirstBirth, remaining_days);    // children of the first child

        for(auto birth = 0; birth < div; birth++) {
            result += fish::start(daysBeforeFirstBirth, remaining_days - (daysBeforeNextBirth + 1) * (birth + 1));
        }
        return result;
    }
};

class fish_simulator {
    std::vector<unsigned int> _fishes;
public:
    explicit fish_simulator(const std::vector<unsigned int>& init_data){
        _fishes = init_data;
    }

    std::size_t simulate(unsigned int rounds) {
        std::size_t result =0;
        for(unsigned int start_day = 1; start_day < 6; start_day++) {
            unsigned int count = std::count(_fishes.begin(), _fishes.end(), start_day);
            if(count > 0) {
                auto created = fish::start(start_day, rounds)*count + count;
                result += created;
            }
        }
        return result;

    }
};


#endif //ADVENT_OF_CODE_FISH_SIMULATOR_H
