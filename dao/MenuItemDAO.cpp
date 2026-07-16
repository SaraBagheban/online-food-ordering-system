#include "MenuItemDAO.h"

#include <memory>

MenuItemDAO::MenuItemDAO(
    DatabaseManager& databaseManager) : databaseManager(databaseManager) {
}

bool MenuItemDAO::addMenuItem(
    int restaurantId,
    const MenuItem& menuItem) {

    sql::Connection* connection =
        databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "INSERT INTO menu_items("
            "restaurant_id,"
            "name,"
            "description,"
            "price,"
            "available,"
            "special_item,"
            "type,"
            "cook_time,"
            "volume"
            ") VALUES(?,?,?,?,?,?,?,?,?)"
        )
    );

    statement->setInt(1, restaurantId);
    statement->setString(2, menuItem.getName());
    statement->setString(3, menuItem.getDescription());
    statement->setDouble(4, menuItem.getPrice());
    statement->setBoolean(5, menuItem.isAvailable());
    statement->setBoolean(6, menuItem.isSpecialItem());

    if (dynamic_cast<const FoodItem*>(&menuItem)) {

        const FoodItem* food =
            dynamic_cast<const FoodItem*>(&menuItem);

        statement->setString(7, "Food");
        statement->setInt(8, food->getCookTime());
        statement->setNull(9, sql::DataType::INTEGER);
    }
    else {

        const DrinkItem* drink =
            dynamic_cast<const DrinkItem*>(&menuItem);

        statement->setString(7, "Drink");
        statement->setNull(8, sql::DataType::INTEGER);
        statement->setInt(9, drink->getVolume());
    }

    return statement->executeUpdate() > 0;
}

bool MenuItemDAO::updateMenuItem(
    const MenuItem& menuItem) {

    sql::Connection* connection =
        databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "UPDATE menu_items SET "
            "name=?,"
            "description=?,"
            "price=?,"
            "available=?,"
            "special_item=?,"
            "cook_time=?,"
            "volume=? "
            "WHERE id=?"
        )
    );

    statement->setString(1, menuItem.getName());
    statement->setString(2, menuItem.getDescription());
    statement->setDouble(3, menuItem.getPrice());
    statement->setBoolean(4, menuItem.isAvailable());
    statement->setBoolean(5, menuItem.isSpecialItem());

    if (dynamic_cast<const FoodItem*>(&menuItem)) {

        const FoodItem* food =
            dynamic_cast<const FoodItem*>(&menuItem);

        statement->setInt(6, food->getCookTime());
        statement->setNull(7, sql::DataType::INTEGER);
    }
    else {

        const DrinkItem* drink =
            dynamic_cast<const DrinkItem*>(&menuItem);

        statement->setNull(6, sql::DataType::INTEGER);
        statement->setInt(7, drink->getVolume());
    }

    statement->setInt(8, menuItem.getId());

    return statement->executeUpdate() > 0;
}
bool MenuItemDAO::deleteMenuItem(int menuItemId) {

    sql::Connection* connection =
        databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "DELETE FROM menu_items "
            "WHERE id=?"
        )
    );

    statement->setInt(1, menuItemId);

    return statement->executeUpdate() > 0;
}

MenuItem* MenuItemDAO::getMenuItemById(
    int menuItemId) {

    sql::Connection* connection =
        databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "SELECT * FROM menu_items "
            "WHERE id=?"
        )
    );

    statement->setInt(1, menuItemId);

    std::unique_ptr<sql::ResultSet> result(
        statement->executeQuery()
    );

    if (!result->next()) {
        return nullptr;
    }

    if (result->getString("type") == "Food") {

        return new FoodItem(
            result->getInt("id"),
            result->getString("name"),
            result->getString("description"),
            result->getDouble("price"),
            result->getBoolean("available"),
            result->getBoolean("special_item"),
            result->getInt("cook_time")
        );
    }

    return new DrinkItem(
        result->getInt("id"),
        result->getString("name"),
        result->getString("description"),
        result->getDouble("price"),
        result->getBoolean("available"),
        result->getBoolean("special_item"),
        result->getInt("volume")
    );
}

std::vector<MenuItem*> MenuItemDAO::getMenu(
    int restaurantId) {

    sql::Connection* connection =
        databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "SELECT * FROM menu_items "
            "WHERE restaurant_id=?"
        )
    );

    statement->setInt(1, restaurantId);

    std::unique_ptr<sql::ResultSet> result(
        statement->executeQuery()
    );

    std::vector<MenuItem*> menu;

    while (result->next()) {

        if (result->getString("type") == "Food") {

            menu.push_back(
                new FoodItem(
                    result->getInt("id"),
                    result->getString("name"),
                    result->getString("description"),
                    result->getDouble("price"),
                    result->getBoolean("available"),
                    result->getBoolean("special_item"),
                    result->getInt("cook_time")
                )
            );
        }
        else {

            menu.push_back(
                new DrinkItem(
                    result->getInt("id"),
                    result->getString("name"),
                    result->getString("description"),
                    result->getDouble("price"),
                    result->getBoolean("available"),
                    result->getBoolean("special_item"),
                    result->getInt("volume")
                )
            );
        }
    }

    return menu;
}
std::vector<MenuItem*> MenuItemDAO::getAvailableMenu(
    int restaurantId) {

    sql::Connection* connection =
        databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "SELECT * FROM menu_items "
            "WHERE restaurant_id=? "
            "AND available=TRUE"
        )
    );

    statement->setInt(1, restaurantId);

    std::unique_ptr<sql::ResultSet> result(
        statement->executeQuery()
    );

    std::vector<MenuItem*> menu;

    while (result->next()) {

        if (result->getString("type") == "Food") {

            menu.push_back(
                new FoodItem(
                    result->getInt("id"),
                    result->getString("name"),
                    result->getString("description"),
                    result->getDouble("price"),
                    result->getBoolean("available"),
                    result->getBoolean("special_item"),
                    result->getInt("cook_time")
                )
            );
        }
        else {

            menu.push_back(
                new DrinkItem(
                    result->getInt("id"),
                    result->getString("name"),
                    result->getString("description"),
                    result->getDouble("price"),
                    result->getBoolean("available"),
                    result->getBoolean("special_item"),
                    result->getInt("volume")
                )
            );
        }
    }

    return menu;
}

bool MenuItemDAO::setAvailability(
    int menuItemId,
    bool available) {

    sql::Connection* connection =
        databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "UPDATE menu_items "
            "SET available=? "
            "WHERE id=?"
        )
    );

    statement->setBoolean(1, available);
    statement->setInt(2, menuItemId);

    return statement->executeUpdate() > 0;
}

bool MenuItemDAO::setSpecialItem(
    int menuItemId,
    bool specialItem) {

    sql::Connection* connection =
        databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "UPDATE menu_items "
            "SET special_item=? "
            "WHERE id=?"
        )
    );

    statement->setBoolean(1, specialItem);
    statement->setInt(2, menuItemId);

    return statement->executeUpdate() > 0;
}