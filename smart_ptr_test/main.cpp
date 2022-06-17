//
// Created by hawk on 17.06.22.
//
#include <memory>

#include "unique_ptr_owner.h"

int main(int argc, char** argv) {

    auto handler = std::make_unique<function_handler>();
    auto owner = std::make_unique<unique_ptr_owner>(std::move(handler));

    function_handler_client client(owner->get_function_handler());
    client.use_handler();

    std::cout << "Now owner will be deleted.\n";

    owner.reset(nullptr);

    client.use_handler();
}