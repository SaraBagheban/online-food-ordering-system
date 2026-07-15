#ifndef GOLDLEVEL_H
#define GOLDLEVEL_H

#include "MembershipLevel.h"

class GoldLevel : public MembershipLevel {
public:
    std::string getLevelName() const override;

    double getDiscount() const override;

    double getPointMultiplier() const override;

    double getShippingCost(double shippingCost, double orderSubtotal) const override;

    int getRequiredPoints() const override;

    int getMonthlyCoupons() const override;

    bool canAccessSpecialMenu() const override;

    bool hasPriorityOrder() const override;
};

#endif