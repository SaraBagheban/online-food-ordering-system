#include "NormalLevel.h"

std::string NormalLevel::getLevelName() const {
    return "Normal";
}

double NormalLevel::getDiscount() const {
    return 0.0;
}

double NormalLevel::getPointMultiplier() const {
    return 1.0;
}

double NormalLevel::getShippingCost(double shippingCost) const {
    return shippingCost;
}

int NormalLevel::getRequiredPoints() const {
    return 0;
}

int NormalLevel::getMonthlyCoupons() const {
    return 0;
}

bool NormalLevel::canAccessSpecialMenu() const {
    return false;
}

bool NormalLevel::hasPriorityOrder() const {
    return false;
}