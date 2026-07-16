#ifndef RESTAURANTADMINMENU_H
#define RESTAURANTADMINMENU_H

#include "../services/RestaurantService.h"
#include "../services/OrderService.h"

class RestaurantAdminMenu {
private:
    RestaurantService& restaurantService;
    OrderService& orderService;

    int adminId;

public:
    RestaurantAdminMenu(
        RestaurantService& restaurantService,
        OrderService& orderService,
        int adminId);

    void show();

private:
    void showRestaurantInformation();

    void editRestaurantInformation();

    void showMenu();

    void addMenuItem();

    void editMenuItem();

    void removeMenuItem();

    void changeAvailability();

    void changeSpecialStatus();

    void showOrders();

    void updateOrderStatus();
};

#endif