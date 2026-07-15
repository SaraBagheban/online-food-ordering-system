#include "SilverLevel.h"

std::string SilverLevel::getLevelName() const {
    return "Silver";
}

double SilverLevel::getDiscount() const {
    return 0.05;
}

double SilverLevel::getPointMultiplier() const {
    return 1.2;
}

double SilverLevel::getShippingCost(double shippingCost, double orderSubtotal) const {
    if (orderSubtotal >= 1000000) {
        return shippingCost * 0.5;
    }

    return shippingCost;
}

int SilverLevel::getRequiredPoints() const {
    return 100;
}

int SilverLevel::getMonthlyCoupons() const {
    return 1;
}

bool SilverLevel::canAccessSpecialMenu() const {
    return false;
}

bool SilverLevel::hasPriorityOrder() const {
    return false;
}