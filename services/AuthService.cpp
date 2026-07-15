#include "AuthService.h"

AuthService::AuthService() {
}

User* AuthService::login(const std::string& phone) {
    return userDAO.getUserByPhone(phone);
}

bool AuthService::registerCustomer(const Customer& customer) {
    if (phoneExists(customer.getPhone())) {
        return false;
    }
    return userDAO.addCustomer(customer);
}

bool AuthService::phoneExists(const std::string& phone) {
    return userDAO.phoneExists(phone);
}

bool AuthService::logout(User* user) {
    if (user == nullptr) {
        return false;
    }

    return true;
}