#include "GoldLevel.h"

std::string GoldLevel::getLevelName() const {
    return "Gold";
}

double GoldLevel::getDiscount() const {
    return 0.10;
}

double GoldLevel::getPointMultiplier() const {
    return 1.5;
}

double GoldLevel::getShippingCost(double shippingCost, double orderSubtotal) const {
    return shippingCost * 0.5;
}

int GoldLevel::getRequiredPoints() const {
    return 300;
}

int GoldLevel::getMonthlyCoupons() const {
    return 2;
}

bool GoldLevel::canAccessSpecialMenu() const {
    return true;
}

bool GoldLevel::hasPriorityOrder() const {
    return false;
}