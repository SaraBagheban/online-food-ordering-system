#include "Customer.h"

#include <iostream>

Customer::Customer() : User() {
}

Customer::Customer(int id, const std::string& name, const std::string& phone)
    : User(id, name, phone) {
}

void Customer::showMenu() {
    std::cout << "Customer Menu" << std::endl;
}