#include "RestaurantService.h"

#include "../models/users/Customer.h"

RestaurantService::RestaurantService() {
}

std::vector<Restaurant*> RestaurantService::getRestaurants() {
    return restaurantDAO.getRestaurants();
}

Restaurant* RestaurantService::getRestaurant(int restaurantId) {
    return restaurantDAO.getRestaurant(restaurantId);
}

std::vector<MenuItem*> RestaurantService::getMenu(int restaurantId) {
    return menuItemDAO.getMenu(restaurantId);
}

std::vector<MenuItem*> RestaurantService::getAvailableMenu(int restaurantId) {
    return menuItemDAO.getAvailableMenu(restaurantId);
}

std::vector<MenuItem*> RestaurantService::getSpecialMenu(int restaurantId) {
    return menuItemDAO.getSpecialMenu(restaurantId);
}

MenuItem* RestaurantService::getMenuItem(int menuItemId) {
    return menuItemDAO.getMenuItem(menuItemId);
}


bool RestaurantService::isRestaurantActive(int restaurantId) {
    Restaurant* restaurant = restaurantDAO.getRestaurant(restaurantId);

    if (restaurant == nullptr) {
        return false;
    }

    return restaurant->getIsActive();
}

bool RestaurantService::isMenuItemAvailable(int menuItemId) {
    MenuItem* item = menuItemDAO.getMenuItem(menuItemId);

    if (item == nullptr) {
        return false;
    }

    return item->getAvailable();
}

bool RestaurantService::canOrderMenuItem(Customer* customer, int menuItemId) {
    MenuItem* item = menuItemDAO.getMenuItem(menuItemId);

    if (item == nullptr) {
        return false;
    }

    if (!item->getAvailable()) {
        return false;
    }

    if (item->isSpecialItem() && !customer->getMembershipLevel()->canAccessSpecialMenu()) {
        return false;
    }

    return true;
}