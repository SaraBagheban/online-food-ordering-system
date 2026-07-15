#include "LevelHistory.h"

LevelHistory::LevelHistory() : oldLevel(""), newLevel(""), loyaltyPoints(0), successfulOrders(0) {
}

LevelHistory::LevelHistory(const std::string& oldLevel, const std::string& newLevel,
                           int loyaltyPoints, int successfulOrders)
    : oldLevel(oldLevel), newLevel(newLevel),
      loyaltyPoints(loyaltyPoints), successfulOrders(successfulOrders) {
}


std::string LevelHistory::getOldLevel() const {
    return oldLevel;
}

std::string LevelHistory::getNewLevel() const {
    return newLevel;
}

int LevelHistory::getLoyaltyPoints() const {
    return loyaltyPoints;
}

int LevelHistory::getSuccessfulOrders() const {
    return successfulOrders;
}


void LevelHistory::setOldLevel(const std::string& oldLevel) {
    this->oldLevel = oldLevel;
}

void LevelHistory::setNewLevel(const std::string& newLevel) {
    this->newLevel = newLevel;
}

void LevelHistory::setLoyaltyPoints(int loyaltyPoints) {
    this->loyaltyPoints = loyaltyPoints;
}

void LevelHistory::setSuccessfulOrders(int successfulOrders) {
    this->successfulOrders = successfulOrders;
}