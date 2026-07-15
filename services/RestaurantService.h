#ifndef RESTAURANTSERVICE_H
#define RESTAURANTSERVICE_H

#include "../dao/RestaurantDAO.h"
#include "../dao/MenuItemDAO.h"
#include "../models/restaurant/Restaurant.h"
#include "../models/restaurant/MenuItem.h"

#include <vector>

class RestaurantService {
private:
    RestaurantDAO restaurantDAO;
    MenuItemDAO menuItemDAO;

public:
    RestaurantService();

    std::vector<Restaurant*> getRestaurants();
    Restaurant* getRestaurant(int restaurantId);
    std::vector<MenuItem*> getMenu(int restaurantId);
    std::vector<MenuItem*> getAvailableMenu(int restaurantId);
    std::vector<MenuItem*> getSpecialMenu(int restaurantId);
    MenuItem* getMenuItem(int menuItemId);


    bool isRestaurantActive(int restaurantId);
    bool isMenuItemAvailable(int menuItemId);
    bool canOrderMenuItem(Customer* customer, int menuItemId);
};

#endif