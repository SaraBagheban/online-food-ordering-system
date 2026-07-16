#ifndef MENUITEMDAO_H
#define MENUITEMDAO_H

#include "../database/DatabaseManager.h"
#include "../models/restaurant/MenuItem.h"
#include "../models/restaurant/FoodItem.h"
#include "../models/restaurant/DrinkItem.h"

#include <vector>

class MenuItemDAO {
private:
    DatabaseManager& databaseManager;

public:
    explicit MenuItemDAO(DatabaseManager& databaseManager);

    bool addMenuItem(int restaurantId, const MenuItem& menuItem);
    bool updateMenuItem(const MenuItem& menuItem);
    bool deleteMenuItem(int menuItemId);

    MenuItem* getMenuItemById(int menuItemId);
    std::vector<MenuItem*> getMenu(int restaurantId);
    std::vector<MenuItem*> getAvailableMenu(int restaurantId);

    bool setAvailability(int menuItemId, bool available);
    bool setSpecialItem(int menuItemId, bool specialItem);
};

#endif