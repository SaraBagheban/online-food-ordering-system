#include "SystemAdmin.h"

#include <iostream>

SystemAdmin::SystemAdmin() : User() {
}

SystemAdmin::SystemAdmin(int id, const std::string& name, const std::string& phone)
    : User(id, name, phone) {
}

void SystemAdmin::showMenu() {
    std::cout << "System Admin Menu" << std::endl;
}