//
// Created by hawk on 18.06.22.
//

#ifndef ADVENT_OF_CODE_FISH_SIMULATOR_H
#define ADVENT_OF_CODE_FISH_SIMULATOR_H

#include <vector>

class fish_simulator {
    std::vector<unsigned int> _fishes;
    unsigned int reset_value = 6;
    unsigned int new_fish_init_value = 8;
public:
    explicit fish_simulator(const std::vector<unsigned int>& init_data){
        _fishes = init_data;
    }

    std::size_t simulate(unsigned int rounds) {
        for(auto round = 0u; round < rounds; round++) {
            unsigned count_added_fishes = 0;
            for(auto& fish : _fishes) {
                if(fish == 0) {
                    count_added_fishes++;
                    fish = reset_value;
                } else {
                    fish--;
                }
            }
            for(auto i=0; i < count_added_fishes; i++) {
                _fishes.push_back(new_fish_init_value);
            }
        }
        return _fishes.size();
    }
};


#endif //ADVENT_OF_CODE_FISH_SIMULATOR_H
