#ifndef RESTAURANTDAO_H
#define RESTAURANTDAO_H

#include "../database/DatabaseManager.h"
#include "../models/restaurant/Restaurant.h"

#include <vector>
#include <string>

class RestaurantDAO {
private:
    DatabaseManager& databaseManager;

public:
    explicit RestaurantDAO(DatabaseManager& databaseManager);

    bool addRestaurant(const Restaurant& restaurant, int ownerId);
    bool updateRestaurant(const Restaurant& restaurant);
    bool deleteRestaurant(int restaurantId);

    Restaurant* getRestaurantById(int restaurantId);
    Restaurant* getRestaurantByOwnerId(int ownerId);
    std::vector<Restaurant> getAllRestaurants();
    std::vector<Restaurant> getActiveRestaurants();

    bool setRestaurantStatus(int restaurantId, bool isActive);
};

#endif