#ifndef SYSTEMADMIN_H
#define SYSTEMADMIN_H

#include "User.h"

class SystemAdmin : public User {
public:
    SystemAdmin();
    SystemAdmin(int id, const std::string& name, const std::string& phone);

    void showMenu() override;
};

#endif