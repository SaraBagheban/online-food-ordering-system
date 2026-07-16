#ifndef SYSTEMADMINMENU_H
#define SYSTEMADMINMENU_H

#include "../services/AuthService.h"
#include "../services/RestaurantService.h"
#include "../services/MembershipService.h"

class SystemAdminMenu {
private:
    AuthService& authService;
    RestaurantService& restaurantService;
    MembershipService& membershipService;

    int adminId;

public:
    SystemAdminMenu(
        AuthService& authService,
        RestaurantService& restaurantService,
        MembershipService& membershipService,
        int adminId);

    void show();

private:
    void registerRestaurantAdmin();

    void registerRestaurant();

    void showAllRestaurants();

    void activateRestaurant();

    void deactivateRestaurant();

    void showMembershipStatistics();

    void showUsers();

    void showSystemStatistics();
};

#endif