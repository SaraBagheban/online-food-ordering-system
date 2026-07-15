#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"
#include "../membership/MembershipLevel.h"
#include "../membership/Badge.h"
#include "../membership/LevelHistory.h"

#include <vector>

class Customer : public User {
private:
    MembershipLevel* membershipLevel;

    int loyaltyPoints;
    int successfulOrders;
    int couponCount;

    std::vector<Badge> badges;
    std::vector<LevelHistory> levelHistory;

public:
    Customer();

    Customer(int id, const std::string& name, const std::string& phone);

    Customer(int id, const std::string& name,
             const std::string& phone,
             MembershipLevel* membershipLevel,
             int loyaltyPoints, int successfulOrders,
             int couponCount);

    ~Customer();



    MembershipLevel* getMembershipLevel() const;

    int getLoyaltyPoints() const;

    int getSuccessfulOrders() const;

    int getCouponCount() const;

    std::vector<Badge>& getBadges();

    std::vector<LevelHistory>& getLevelHistory();



    void setMembershipLevel(MembershipLevel* membershipLevel);

    void setLoyaltyPoints(int loyaltyPoints);

    void setSuccessfulOrders(int successfulOrders);

    void setCouponCount(int couponCount);



    void addBadge(const Badge& badge);

    void addLevelHistory(const LevelHistory& history);

    void showMenu() override;
};

#endif