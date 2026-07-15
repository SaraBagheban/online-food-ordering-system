#ifndef LEVELHISTORY_H
#define LEVELHISTORY_H

#include <string>

class LevelHistory {
private:
    std::string oldLevel;
    std::string newLevel;

    int loyaltyPoints;
    int successfulOrders;

public:
    LevelHistory();
    LevelHistory(const std::string& oldLevel, const std::string& newLevel,
                 int loyaltyPoints, int successfulOrders);



    std::string getOldLevel() const;
    std::string getNewLevel() const;
    int getLoyaltyPoints() const;
    int getSuccessfulOrders() const;

    void setOldLevel(const std::string& oldLevel);
    void setNewLevel(const std::string& newLevel);
    void setLoyaltyPoints(int loyaltyPoints);
    void setSuccessfulOrders(int successfulOrders);
};

#endif