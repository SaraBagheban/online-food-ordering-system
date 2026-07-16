#ifndef MEMBERSHIPDAO_H
#define MEMBERSHIPDAO_H

#include "../database/DatabaseManager.h"
#include "../models/membership/Badge.h"
#include "../models/membership/LevelHistory.h"

#include <vector>

class MembershipDAO {
private:
    DatabaseManager& databaseManager;

public:
    explicit MembershipDAO(DatabaseManager& databaseManager);

    bool addPoints(int customerId,
                   int points);

    bool removePoints(int customerId,
                      int points);

    bool checkLevelUpgrade(int customerId);

    bool checkLevelDowngrade(int customerId);

    bool assignMonthlyCoupons(int customerId);

    bool checkBadges(int customerId);

    bool addLevelHistory(
        const LevelHistory& history);

    int getRemainingPoints(int customerId);

    std::vector<Badge> getBadges(
        int customerId);

    std::vector<LevelHistory> getLevelHistory(
        int customerId);

    int getNormalMemberCount();

    int getSilverMemberCount();

    int getGoldMemberCount();

    int getVIPMemberCount();
};

#endif