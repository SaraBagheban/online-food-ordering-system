#include "VIPLevel.h"

std::string VIPLevel::getLevelName() const {
    return "VIP";
}

double VIPLevel::getDiscount() const {
    return 0.15;
}

double VIPLevel::getPointMultiplier() const {
    return 2.0;
}

double VIPLevel::getShippingCost(double shippingCost, double orderSubtotal) const {
    return 0;
}

int VIPLevel::getRequiredPoints() const {
    return 700;
}

int VIPLevel::getMonthlyCoupons() const {
    return 3;
}

bool VIPLevel::canAccessSpecialMenu() const {
    return true;
}

bool VIPLevel::hasPriorityOrder() const {
    return true;
}