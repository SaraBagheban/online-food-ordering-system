#ifndef AUTHSERVICE_H
#define AUTHSERVICE_H

#include "../dao/UserDAO.h"
#include "../models/users/User.h"
#include "../models/users/Customer.h"

#include <string>

class AuthService {
private:
    UserDAO userDAO;

public:
    AuthService();

    User* login(const std::string& phone);

    bool registerCustomer(const Customer& customer);

    bool phoneExists(const std::string& phone);

    bool logout(User* user);
};

#endif