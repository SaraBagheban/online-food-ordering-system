#include "RestaurantDAO.h"

#include <memory>

RestaurantDAO::RestaurantDAO(DatabaseManager& databaseManager)
    : databaseManager(databaseManager) {
}

bool RestaurantDAO::addRestaurant(const Restaurant& restaurant, int ownerId) {

    sql::Connection* connection =
        databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "INSERT INTO restaurants("
            "owner_id,"
            "name,"
            "address,"
            "phone,"
            "description,"
            "prep_time,"
            "is_active"
            ") VALUES(?,?,?,?,?,?,?)"
        )
    );

    statement->setInt(1, ownerId);
    statement->setString(2, restaurant.getName());
    statement->setString(3, restaurant.getAddress());
    statement->setString(4, restaurant.getPhone());
    statement->setString(5, restaurant.getDescription());
    statement->setInt(6, restaurant.getPrepTime());
    statement->setBoolean(7, restaurant.getIsActive());

    return statement->executeUpdate() > 0;
}

bool RestaurantDAO::updateRestaurant(const Restaurant& restaurant) {

    sql::Connection* connection = databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "UPDATE restaurants SET "
            "name=?,"
            "address=?,"
            "phone=?,"
            "description=?,"
            "prep_time=?,"
            "is_active=? "
            "WHERE id=?"
        )
    );

    statement->setString(1, restaurant.getName());
    statement->setString(2, restaurant.getAddress());
    statement->setString(3, restaurant.getPhone());
    statement->setString(4, restaurant.getDescription());
    statement->setInt(5, restaurant.getPrepTime());
    statement->setBoolean(6, restaurant.getIsActive());
    statement->setInt(7, restaurant.getId());

    return statement->executeUpdate() > 0;
}

bool RestaurantDAO::deleteRestaurant(int restaurantId) {

    sql::Connection* connection = databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "DELETE FROM restaurants WHERE id=?"
        )
    );

    statement->setInt(1, restaurantId);

    return statement->executeUpdate() > 0;
}

Restaurant* RestaurantDAO::getRestaurantById(
    int restaurantId) {

    sql::Connection* connection = databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "SELECT * FROM restaurants WHERE id=?"
        )
    );

    statement->setInt(1, restaurantId);

    std::unique_ptr<sql::ResultSet> result(
        statement->executeQuery()
    );

    if (!result->next()) {
        return nullptr;
    }

    return new Restaurant(
        result->getInt("id"),
        result->getString("name"),
        result->getString("address"),
        result->getString("phone"),
        result->getString("description"),
        result->getInt("prep_time"),
        result->getBoolean("is_active")
    );
}

Restaurant* RestaurantDAO::getRestaurantByOwnerId(int ownerId) {

    sql::Connection* connection = databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "SELECT * FROM restaurants "
            "WHERE owner_id=?"
        )
    );

    statement->setInt(1, ownerId);

    std::unique_ptr<sql::ResultSet> result(
        statement->executeQuery()
    );

    if (!result->next()) {
        return nullptr;
    }

    return new Restaurant(
        result->getInt("id"),
        result->getString("name"),
        result->getString("address"),
        result->getString("phone"),
        result->getString("description"),
        result->getInt("prep_time"),
        result->getBoolean("is_active")
    );
}

std::vector<Restaurant>
RestaurantDAO::getAllRestaurants() {

    sql::Connection* connection = databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "SELECT * FROM restaurants"
        )
    );

    std::unique_ptr<sql::ResultSet> result(
        statement->executeQuery()
    );

    std::vector<Restaurant> restaurants;

    while (result->next()) {

        restaurants.emplace_back(
            result->getInt("id"),
            result->getString("name"),
            result->getString("address"),
            result->getString("phone"),
            result->getString("description"),
            result->getInt("prep_time"),
            result->getBoolean("is_active")
        );
    }

    return restaurants;
}

std::vector<Restaurant>
RestaurantDAO::getActiveRestaurants() {

    sql::Connection* connection =
        databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "SELECT * FROM restaurants "
            "WHERE is_active = TRUE"
        )
    );

    std::unique_ptr<sql::ResultSet> result(
        statement->executeQuery()
    );

    std::vector<Restaurant> restaurants;

    while (result->next()) {

        restaurants.emplace_back(
            result->getInt("id"),
            result->getString("name"),
            result->getString("address"),
            result->getString("phone"),
            result->getString("description"),
            result->getInt("prep_time"),
            result->getBoolean("is_active")
        );
    }

    return restaurants;
}

bool RestaurantDAO::setRestaurantStatus( int restaurantId, bool isActive) {

    sql::Connection* connection = databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "UPDATE restaurants "
            "SET is_active=? "
            "WHERE id=?"
        )
    );

    statement->setBoolean(1, isActive);
    statement->setInt(2, restaurantId);

    return statement->executeUpdate() > 0;
}