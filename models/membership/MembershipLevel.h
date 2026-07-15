#ifndef MEMBERSHIPLEVEL_H
#define MEMBERSHIPLEVEL_H

#include <string>

class MembershipLevel {
public:
    virtual ~MembershipLevel();

    virtual std::string getLevelName() const = 0;

    virtual double getDiscount() const = 0;

    virtual double getPointMultiplier() const = 0;

    virtual double getShippingCost(double shippingCost) const = 0;

    virtual int getRequiredPoints() const = 0;

    virtual int getMonthlyCoupons() const = 0;

    virtual bool canAccessSpecialMenu() const = 0;

    virtual bool hasPriorityOrder() const = 0;
};

#endif