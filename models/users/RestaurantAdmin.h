#ifndef RESTAURANTADMIN_H
#define RESTAURANTADMIN_H

#include "User.h"

class RestaurantAdmin : public User {
public:
    RestaurantAdmin();
    RestaurantAdmin(int id, const std::string& name, const std::string& phone);

    void showMenu() override;
};

#endif