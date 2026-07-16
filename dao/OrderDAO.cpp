#include "OrderDAO.h"

#include <memory>

OrderDAO::OrderDAO(
    DatabaseManager& databaseManager)
    : databaseManager(databaseManager) {
}

bool OrderDAO::addOrder(
    const Order& order) {

    sql::Connection* connection =
        databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "INSERT INTO orders("
            "customer_id,"
            "restaurant_id,"
            "status,"
            "membership_level,"
            "subtotal,"
            "discount,"
            "shipping_cost,"
            "total_price,"
            "earned_points"
            ") VALUES(?,?,?,?,?,?,?,?,?)"
        )
    );

    statement->setInt(
        1,
        order.getCustomerId()
    );

    statement->setInt(
        2,
        order.getRestaurantId()
    );

    statement->setString(
        3,
        order.getStatusString()
    );

    statement->setString(
        4,
        order.getMembershipLevel()
    );

    statement->setDouble(
        5,
        order.getSubtotal()
    );

    statement->setDouble(
        6,
        order.getDiscount()
    );

    statement->setDouble(
        7,
        order.getShippingCost()
    );

    statement->setDouble(
        8,
        order.getTotalPrice()
    );

    statement->setInt(
        9,
        order.getEarnedPoints()
    );

    return statement->executeUpdate() > 0;
}

bool OrderDAO::addOrderItem(
    int orderId,
    int menuItemId,
    int quantity,
    double price) {

    sql::Connection* connection =
        databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "INSERT INTO order_items("
            "order_id,"
            "menu_item_id,"
            "quantity,"
            "price"
            ") VALUES(?,?,?,?)"
        )
    );

    statement->setInt(1, orderId);
    statement->setInt(2, menuItemId);
    statement->setInt(3, quantity);
    statement->setDouble(4, price);

    return statement->executeUpdate() > 0;
}
Order* OrderDAO::getOrderById(
    int orderId) {

    sql::Connection* connection =
        databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "SELECT * FROM orders "
            "WHERE id=?"
        )
    );

    statement->setInt(1, orderId);

    std::unique_ptr<sql::ResultSet> result(
        statement->executeQuery()
    );

    if (!result->next()) {
        return nullptr;
    }

    Order* order = new Order();

    order->setId(
        result->getInt("id")
    );

    order->setCustomerId(
        result->getInt("customer_id")
    );

    order->setRestaurantId(
        result->getInt("restaurant_id")
    );

    order->setStatus(
        stringToOrderStatus(
            result->getString("status")
        )
    );

    order->setMembershipLevel(
        result->getString("membership_level")
    );

    order->setSubtotal(
        result->getDouble("subtotal")
    );

    order->setDiscount(
        result->getDouble("discount")
    );

    order->setShippingCost(
        result->getDouble("shipping_cost")
    );

    order->setTotalPrice(
        result->getDouble("total_price")
    );

    order->setEarnedPoints(
        result->getInt("earned_points")
    );

    return order;
}

std::vector<Order>
OrderDAO::getCustomerOrders(
    int customerId) {

    sql::Connection* connection =
        databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "SELECT * FROM orders "
            "WHERE customer_id=? "
            "ORDER BY order_date DESC"
        )
    );

    statement->setInt(1, customerId);

    std::unique_ptr<sql::ResultSet> result(
        statement->executeQuery()
    );

    std::vector<Order> orders;

    while (result->next()) {

        Order order;

        order.setId(result->getInt("id"));
        order.setCustomerId(
            result->getInt("customer_id")
        );
        order.setRestaurantId(
            result->getInt("restaurant_id")
        );
        order.setStatus(
            stringToOrderStatus(
                result->getString("status")
            )
        );
        order.setMembershipLevel(
            result->getString(
                "membership_level"
            )
        );
        order.setSubtotal(
            result->getDouble("subtotal")
        );
        order.setDiscount(
            result->getDouble("discount")
        );
        order.setShippingCost(
            result->getDouble("shipping_cost")
        );
        order.setTotalPrice(
            result->getDouble("total_price")
        );
        order.setEarnedPoints(
            result->getInt("earned_points")
        );

        orders.push_back(order);
    }

    return orders;
}
std::vector<Order>
OrderDAO::getRestaurantOrders(
    int restaurantId) {

    sql::Connection* connection =
        databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "SELECT * FROM orders "
            "WHERE restaurant_id=? "
            "ORDER BY order_date DESC"
        )
    );

    statement->setInt(1, restaurantId);

    std::unique_ptr<sql::ResultSet> result(
        statement->executeQuery()
    );

    std::vector<Order> orders;

    while (result->next()) {

        Order order;

        order.setId(result->getInt("id"));
        order.setCustomerId(result->getInt("customer_id"));
        order.setRestaurantId(result->getInt("restaurant_id"));
        order.setStatus(
            stringToOrderStatus(
                result->getString("status")
            )
        );
        order.setMembershipLevel(
            result->getString("membership_level")
        );
        order.setSubtotal(result->getDouble("subtotal"));
        order.setDiscount(result->getDouble("discount"));
        order.setShippingCost(result->getDouble("shipping_cost"));
        order.setTotalPrice(result->getDouble("total_price"));
        order.setEarnedPoints(result->getInt("earned_points"));

        orders.push_back(order);
    }

    return orders;
}

std::vector<Order>
OrderDAO::getOrdersByStatus(
    OrderStatus status) {

    sql::Connection* connection =
        databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "SELECT * FROM orders "
            "WHERE status=? "
            "ORDER BY order_date DESC"
        )
    );

    statement->setString(
        1,
        orderStatusToString(status)
    );

    std::unique_ptr<sql::ResultSet> result(
        statement->executeQuery()
    );

    std::vector<Order> orders;

    while (result->next()) {

        Order order;

        order.setId(result->getInt("id"));
        order.setCustomerId(result->getInt("customer_id"));
        order.setRestaurantId(result->getInt("restaurant_id"));
        order.setStatus(
            stringToOrderStatus(
                result->getString("status")
            )
        );
        order.setMembershipLevel(
            result->getString("membership_level")
        );
        order.setSubtotal(result->getDouble("subtotal"));
        order.setDiscount(result->getDouble("discount"));
        order.setShippingCost(result->getDouble("shipping_cost"));
        order.setTotalPrice(result->getDouble("total_price"));
        order.setEarnedPoints(result->getInt("earned_points"));

        orders.push_back(order);
    }

    return orders;
}
bool OrderDAO::updateOrderStatus(
    int orderId,
    OrderStatus status) {

    sql::Connection* connection =
        databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "UPDATE orders "
            "SET status=? "
            "WHERE id=?"
        )
    );

    statement->setString(
        1,
        orderStatusToString(status)
    );

    statement->setInt(2, orderId);

    return statement->executeUpdate() > 0;
}

int OrderDAO::getLastOrderId() {

    sql::Connection* connection =
        databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "SELECT MAX(id) AS last_id "
            "FROM orders"
        )
    );

    std::unique_ptr<sql::ResultSet> result(
        statement->executeQuery()
    );

    if (!result->next()) {
        return -1;
    }

    if (result->isNull("last_id")) {
        return -1;
    }

    return result->getInt("last_id");
}