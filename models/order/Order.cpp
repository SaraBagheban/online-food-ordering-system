#include "Order.h"

#include <iostream>

Order::Order() : id(0),customerId(0),restaurantId(0),basePrice(0),
      membershipDiscount(0),couponDiscount(0),shippingCost(0),
      finalPrice(0), earnedPoints(0), status(UNKNOWN) {
}

Order::Order(int id, int customerId, int restaurantId, const std::vector<CartItem>& items,
             double basePrice, double membershipDiscount, double couponDiscount,
             double shippingCost, double finalPrice, int earnedPoints, OrderStatus status)
    : id(id), customerId(customerId), restaurantId(restaurantId),
      items(items), basePrice(basePrice), membershipDiscount(membershipDiscount),
      couponDiscount(couponDiscount), shippingCost(shippingCost),
      finalPrice(finalPrice), earnedPoints(earnedPoints), status(status) {
}



int Order::getId() const {
    return id;
}

int Order::getCustomerId() const {
    return customerId;
}

int Order::getRestaurantId() const {
    return restaurantId;
}

const std::vector<CartItem>& Order::getItems() const {
    return items;
}

double Order::getBasePrice() const {
    return basePrice;
}

double Order::getMembershipDiscount() const {
    return membershipDiscount;
}

double Order::getCouponDiscount() const {
    return couponDiscount;
}

double Order::getShippingCost() const {
    return shippingCost;
}

double Order::getFinalPrice() const {
    return finalPrice;
}

int Order::getEarnedPoints() const {
    return earnedPoints;
}

OrderStatus Order::getStatus() const {
    return status;
}



void Order::setId(int id) {
    this->id = id;
}

void Order::setCustomerId(int customerId) {
    this->customerId = customerId;
}

void Order::setRestaurantId(int restaurantId) {
    this->restaurantId = restaurantId;
}

void Order::setItems(const std::vector<CartItem>& items) {
    this->items = items;
}

void Order::setBasePrice(double basePrice) {
    this->basePrice = basePrice;
}

void Order::setMembershipDiscount(double membershipDiscount) {
    this->membershipDiscount = membershipDiscount;
}

void Order::setCouponDiscount(double couponDiscount) {
    this->couponDiscount = couponDiscount;
}

void Order::setShippingCost(double shippingCost) {
    this->shippingCost = shippingCost;
}

void Order::setFinalPrice(double finalPrice) {
    this->finalPrice = finalPrice;
}

void Order::setEarnedPoints(int earnedPoints) {
    this->earnedPoints = earnedPoints;
}

void Order::setStatus(OrderStatus status) {
    this->status = status;
}

void Order::showOrder() const {

    std::cout << std::endl;
    std::cout << "============== ORDER ==============" << std::endl << std::endl;

    std::cout << "Order ID: " << id << std::endl;

    std::cout << "Customer ID: " << customerId << std::endl;

    std::cout << "Restaurant ID: " << restaurantId << std::endl;

    std::cout << std::endl;

    std::cout << "--------------- ITEMS --------------" << std::endl;

    for (int i = 0; i < items.size(); i++) {

        std::cout << items[i].getItemName() << std::endl;

        std::cout << "Quantity: " << items[i].getQuantity() << std::endl;

        std::cout << "Unit Price: " << items[i].getUnitPrice() << std::endl;

        std::cout << "Item Total: " << items[i].getTotalPrice() << std::endl;

        std::cout << "------------------------------------" << std::endl;
    }

    std::cout << std::endl;
    std::cout << "-------------- INVOICE -------------" << std::endl;

    std::cout << "Base Price:             " << basePrice << std::endl;

    std::cout << "Membership Discount:   -" << membershipDiscount << std::endl;

    std::cout << "Coupon Discount:       -" << couponDiscount << std::endl;

    std::cout << "Shipping Cost:          " << shippingCost << std::endl;

    std::cout << "------------------------------------" << std::endl;

    std::cout << "Final Price:            " << finalPrice << std::endl;

    std::cout << "Earned Points:          " << earnedPoints << std::endl;
    
    std::cout << "Status:                 " << orderStatusToString(status) << std::endl;

    std::cout << "====================================" << std::endl << std::endl;
}