#ifndef MEMBERSHIPSERVICE_H
#define MEMBERSHIPSERVICE_H

#include "../dao/MembershipDAO.h"
#include "../models/users/Customer.h"
#include "../models/membership/Badge.h"
#include "../models/membership/LevelHistory.h"

#include <vector>
#include <string>

class MembershipService {
private:
    MembershipDAO membershipDAO;

public:
    MembershipService();

    bool addPoints(Customer* customer, int earnedPoints);

    bool removePoints(Customer* customer, int points);

    bool checkLevelUpgrade(Customer* customer);

    bool checkLevelDowngrade(Customer* customer);

    bool assignMonthlyCoupons(Customer* customer);

    bool checkBadges(Customer* customer);

    bool addLevelHistory(Customer* customer, const std::string& oldLevel, const std::string& newLevel);

    int getRemainingPoints(Customer* customer);

    std::vector<Badge> getBadges(Customer* customer);

    std::vector<LevelHistory> getLevelHistory(Customer* customer);

    int getNormalMemberCount();

    int getSilverMemberCount();

    int getGoldMemberCount();

    int getVIPMemberCount();
};

#endif