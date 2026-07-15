#include "OrderService.h"

OrderService::OrderService() {
}

bool OrderService::checkout(Customer* customer) {

    if (cartDAO.isCartEmpty(customer->getId())) {
        return false;
    }

    double subtotal = cartDAO.calculateSubtotal(customer->getId());

    double finalPrice = calculateFinalPrice(customer, subtotal);

    double shippingCost = calculateShippingCost(customer, subtotal);

    int earnedPoints = calculateEarnedPoints(customer, finalPrice);

    bool success = orderDAO.checkout(customer->getId(), finalPrice, shippingCost, earnedPoints);

    if (!success) {
        return false;
    }

    membershipService.addPoints(customer, earnedPoints);

    membershipService.checkLevelUpgrade(customer);

    membershipService.assignMonthlyCoupons(customer);

    membershipService.checkBadges(customer);

    return true;
}

std::vector<Order*> OrderService::getOrders(Customer* customer) {
    return orderDAO.getOrders(customer->getId());
}

Order* OrderService::getOrder(int orderId) {
    return orderDAO.getOrder(orderId);
}

bool OrderService::cancelOrder(Customer* customer, int orderId) {
    return orderDAO.cancelOrder(customer->getId(), orderId);
}

bool OrderService::completeOrder(int orderId) {
    return orderDAO.completeOrder(orderId);
}

double OrderService::calculateDiscount(Customer* customer, double subtotal) {
    return subtotal *customer->getMembershipLevel()->getDiscount();
}

double OrderService::calculateShippingCost(Customer* customer, double subtotal) {
    return customer->getMembershipLevel()->getShippingCost(subtotal);
}

double OrderService::calculateFinalPrice(Customer* customer, double subtotal) {
    return subtotal - calculateDiscount(customer, subtotal) + calculateShippingCost(customer, subtotal);
}

int OrderService::calculateEarnedPoints(Customer* customer, double finalPrice) {
    return static_cast<int>(finalPrice / 10000.0 *
        customer->getMembershipLevel()->getPointMultiplier()
    );
}