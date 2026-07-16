#ifndef ORDERDAO_H
#define ORDERDAO_H

#include "../database/DatabaseManager.h"

#include "../models/order/Order.h"

#include <vector>

class OrderDAO {
private:
    DatabaseManager& databaseManager;

public:
    explicit OrderDAO(DatabaseManager& databaseManager);

    bool addOrder(const Order& order);

    bool addOrderItem(int orderId,
                      int menuItemId,
                      int quantity,
                      double price);

    Order* getOrderById(int orderId);

    std::vector<Order> getCustomerOrders(int customerId);

    std::vector<Order> getRestaurantOrders(int restaurantId);

    std::vector<Order> getOrdersByStatus(
        OrderStatus status);

    bool updateOrderStatus(int orderId,
                           OrderStatus status);

    int getLastOrderId();
};

#endif