#include "CartDAO.h"

#include "../models/order/CartItem.h"
#include "../dao/MenuItemDAO.h"

#include <memory>

CartDAO::CartDAO(DatabaseManager& databaseManager)
    : databaseManager(databaseManager) {
}

int CartDAO::getCartId(int customerId) {

    sql::Connection* connection = databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "SELECT id FROM cart "
            "WHERE customer_id=?"
        )
    );

    statement->setInt(1, customerId);

    std::unique_ptr<sql::ResultSet> result(
        statement->executeQuery()
    );

    if (result->next()) {
        return result->getInt("id");
    }

    return -1;
}

bool CartDAO::createCart(int customerId) {

    sql::Connection* connection = databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "INSERT INTO cart(customer_id)"
            " VALUES(?)"
        )
    );

    statement->setInt(1, customerId);

    return statement->executeUpdate() > 0;
}

bool CartDAO::addItem(int customerId, int menuItemId, int quantity) {

    int cartId = getCartId(customerId);

    if (cartId == -1) {

        if (!createCart(customerId)) {
            return false;
        }

        cartId = getCartId(customerId);
    }

    sql::Connection* connection = databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "INSERT INTO cart_items("
            "cart_id,"
            "menu_item_id,"
            "quantity"
            ") VALUES(?,?,?)"
        )
    );

    statement->setInt(1, cartId);
    statement->setInt(2, menuItemId);
    statement->setInt(3, quantity);

    return statement->executeUpdate() > 0;
}
bool CartDAO::removeItem(int customerId,
                         int menuItemId) {

    int cartId = getCartId(customerId);

    if (cartId == -1) {
        return false;
    }

    sql::Connection* connection =
        databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "DELETE FROM cart_items "
            "WHERE cart_id=? "
            "AND menu_item_id=?"
        )
    );

    statement->setInt(1, cartId);
    statement->setInt(2, menuItemId);

    return statement->executeUpdate() > 0;
}

bool CartDAO::updateQuantity(int customerId,
                             int menuItemId,
                             int quantity) {

    int cartId = getCartId(customerId);

    if (cartId == -1) {
        return false;
    }

    sql::Connection* connection =
        databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "UPDATE cart_items "
            "SET quantity=? "
            "WHERE cart_id=? "
            "AND menu_item_id=?"
        )
    );

    statement->setInt(1, quantity);
    statement->setInt(2, cartId);
    statement->setInt(3, menuItemId);

    return statement->executeUpdate() > 0;
}

bool CartDAO::clearCart(int customerId) {

    int cartId = getCartId(customerId);

    if (cartId == -1) {
        return false;
    }

    sql::Connection* connection =
        databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "DELETE FROM cart_items "
            "WHERE cart_id=?"
        )
    );

    statement->setInt(1, cartId);

    return statement->executeUpdate() > 0;
}

bool CartDAO::isCartEmpty(int customerId) {

    int cartId = getCartId(customerId);

    if (cartId == -1) {
        return true;
    }

    sql::Connection* connection =
        databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "SELECT COUNT(*) "
            "FROM cart_items "
            "WHERE cart_id=?"
        )
    );

    statement->setInt(1, cartId);

    std::unique_ptr<sql::ResultSet> result(
        statement->executeQuery()
    );

    result->next();

    return result->getInt(1) == 0;
}
Cart* CartDAO::getCart(int customerId) {

    int cartId = getCartId(customerId);

    if (cartId == -1) {
        return nullptr;
    }

    Cart* cart = new Cart();

    sql::Connection* connection =
        databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "SELECT * "
            "FROM cart_items "
            "WHERE cart_id=?"
        )
    );

    statement->setInt(1, cartId);

    std::unique_ptr<sql::ResultSet> result(
        statement->executeQuery()
    );

    MenuItemDAO menuItemDAO(databaseManager);

    while (result->next()) {

        MenuItem* menuItem =
            menuItemDAO.getMenuItemById(
                result->getInt("menu_item_id")
            );

        if (menuItem == nullptr) {
            continue;
        }

        CartItem item(
            menuItem,
            result->getInt("quantity")
        );

        cart->addItem(item);
    }

    return cart;
}

double CartDAO::calculateSubtotal(
    int customerId) {

    Cart* cart = getCart(customerId);

    if (cart == nullptr) {
        return 0.0;
    }

    double subtotal = cart->calculateSubtotal();

    delete cart;

    return subtotal;
}