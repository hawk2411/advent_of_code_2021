//
// Created by hawk on 17.06.22.
//

#ifndef ADVENT_OF_CODE_UNIQUE_PTR_OWNER_H
#define ADVENT_OF_CODE_UNIQUE_PTR_OWNER_H

#include <memory>
#include <iostream>

class function_handler {
public:
    void do_something(){ std::cout << "I do something " << ++_count_something << "\n"; }

private:
    int _count_something=0;
};

class function_handler_client {
public:
    explicit function_handler_client(const std::shared_ptr<function_handler>& init_ptr) {
        _function_handler = init_ptr;
    }
    void use_handler(){
        for(int i = 0; i < 10; i++) {
            _function_handler->do_something();
        }
    }
private:
    std::shared_ptr<function_handler> _function_handler;
};

class unique_ptr_owner {
public:
    explicit unique_ptr_owner(std::unique_ptr<function_handler> init_ptr) {
        _function_handler_ptr = std::move(init_ptr);
    };

    [[nodiscard]] std::shared_ptr<function_handler> get_function_handler()const{
        return std::shared_ptr<function_handler>(_function_handler_ptr.get());
    }

private:
    std::unique_ptr<function_handler> _function_handler_ptr;
};



#endif //ADVENT_OF_CODE_UNIQUE_PTR_OWNER_H
