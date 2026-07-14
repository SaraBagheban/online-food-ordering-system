#include "RestaurantAdmin.h"

#include <iostream>

RestaurantAdmin::RestaurantAdmin() : User() {
}

RestaurantAdmin::RestaurantAdmin(int id, const std::string& name, const std::string& phone)
    : User(id, name, phone) {
}

void RestaurantAdmin::showMenu() {
    std::cout << "Restaurant Admin Menu" << std::endl;
}