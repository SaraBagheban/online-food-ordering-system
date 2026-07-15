#include "Customer.h"

#include <iostream>

Customer::Customer() : User(), membershipLevel(nullptr),
      loyaltyPoints(0), successfulOrders(0), couponCount(0) {
}

Customer::Customer(int id, const std::string& name, const std::string& phone)
    : User(id, name, phone), membershipLevel(nullptr),
      loyaltyPoints(0), successfulOrders(0), couponCount(0) {
}

Customer::Customer(int id, const std::string& name, const std::string& phone,
                   MembershipLevel* membershipLevel, int loyaltyPoints,
                   int successfulOrders, int couponCount)
    : User(id, name, phone), membershipLevel(membershipLevel),
      loyaltyPoints(loyaltyPoints), successfulOrders(successfulOrders),
      couponCount(couponCount) {
}

Customer::~Customer() {
}



MembershipLevel* Customer::getMembershipLevel() const {
    return membershipLevel;
}

int Customer::getLoyaltyPoints() const {
    return loyaltyPoints;
}

int Customer::getSuccessfulOrders() const {
    return successfulOrders;
}

int Customer::getCouponCount() const {
    return couponCount;
}

std::vector<Badge>& Customer::getBadges() {
    return badges;
}

std::vector<LevelHistory>& Customer::getLevelHistory() {
    return levelHistory;
}



void Customer::setMembershipLevel(MembershipLevel* membershipLevel) {
    this->membershipLevel = membershipLevel;
}

void Customer::setLoyaltyPoints(int loyaltyPoints) {
    this->loyaltyPoints = loyaltyPoints;
}

void Customer::setSuccessfulOrders(int successfulOrders) {
    this->successfulOrders = successfulOrders;
}

void Customer::setCouponCount(int couponCount) {
    this->couponCount = couponCount;
}



void Customer::addBadge(const Badge& badge) {
    badges.push_back(badge);
}

void Customer::addLevelHistory(const LevelHistory& history) {
    levelHistory.push_back(history);
}

void Customer::showMenu() {
    std::cout << "Customer Menu" << std::endl;
}