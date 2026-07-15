#ifndef ORDERSERVICE_H
#define ORDERSERVICE_H

#include "../dao/OrderDAO.h"
#include "../dao/CartDAO.h"
#include "MembershipService.h"
#include "../models/order/Order.h"
#include "../models/users/Customer.h"

#include <vector>

class OrderService {
private:
    OrderDAO orderDAO;
    CartDAO cartDAO;
    MembershipService membershipService;

public:
    OrderService();

    bool checkout(Customer* customer);

    std::vector<Order*> getOrders(Customer* customer);

    Order* getOrder(int orderId);

    bool cancelOrder(Customer* customer, int orderId);

    bool completeOrder(int orderId);

    double calculateDiscount(Customer* customer, double subtotal);

    double calculateShippingCost(Customer* customer, double subtotal);

    double calculateFinalPrice(Customer* customer, double subtotal);

    int calculateEarnedPoints(Customer* customer,double finalPrice);
};

#endif