#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"

class Customer : public User {
public:
    Customer();
    Customer(int id, const std::string& name, const std::string& phone);

    void showMenu() override;
};

#endif