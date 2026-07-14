#ifndef ORDER_H
#define ORDER_H

#include "CartItem.h"
#include "OrderStatus.h"

#include <vector>

class Order {
private:
    int id;
    int customerId;
    int restaurantId;
    std::vector<CartItem> items;
    double basePrice;
    double membershipDiscount;
    double couponDiscount;
    double shippingCost;
    double finalPrice;
    int earnedPoints;

    OrderStatus status;

public:
    Order();

    Order(int id, int customerId, int restaurantId, const std::vector<CartItem>& items,
        double basePrice, double membershipDiscount, double couponDiscount, double shippingCost,
        double finalPrice, int earnedPoints, OrderStatus status);


    int getId() const;
    int getCustomerId() const;
    int getRestaurantId() const;
    const std::vector<CartItem>& getItems() const;
    double getBasePrice() const;
    double getMembershipDiscount() const;
    double getCouponDiscount() const;
    double getShippingCost() const;
    double getFinalPrice() const;
    int getEarnedPoints() const;
    OrderStatus getStatus() const;

    void setId(int id);
    void setCustomerId(int customerId);
    void setRestaurantId(int restaurantId);
    void setItems(const std::vector<CartItem>& items);
    void setBasePrice(double basePrice);
    void setMembershipDiscount(double membershipDiscount);
    void setCouponDiscount(double couponDiscount);
    void setShippingCost(double shippingCost);
    void setFinalPrice(double finalPrice);
    void setEarnedPoints(int earnedPoints);
    void setStatus(OrderStatus status);

    void showOrder() const;
};

#endif