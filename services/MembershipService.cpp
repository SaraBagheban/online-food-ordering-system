#include "MembershipService.h"

MembershipService::MembershipService() {
}

bool MembershipService::addPoints(Customer* customer, int earnedPoints) {
    return membershipDAO.addPoints(customer->getId(), earnedPoints);
}

bool MembershipService::removePoints(Customer* customer, int points) {
    return membershipDAO.removePoints(customer->getId(), points);
}

bool MembershipService::checkLevelUpgrade(Customer* customer) {
    return membershipDAO.checkLevelUpgrade(customer->getId());
}

bool MembershipService::checkLevelDowngrade(Customer* customer) {
    return membershipDAO.checkLevelDowngrade(customer->getId());
}

bool MembershipService::assignMonthlyCoupons(Customer* customer) {
    return membershipDAO.assignMonthlyCoupons(customer->getId());
}

bool MembershipService::checkBadges(Customer* customer) {
    return membershipDAO.checkBadges(customer->getId());
}

bool MembershipService::addLevelHistory(Customer* customer,const std::string& oldLevel,const std::string& newLevel) {
    return membershipDAO.addLevelHistory(customer->getId(), oldLevel, newLevel);
}

int MembershipService::getRemainingPoints(Customer* customer) {
    return membershipDAO.getRemainingPoints(customer->getId());
}

std::vector<Badge> MembershipService::getBadges(Customer* customer) {
    return membershipDAO.getBadges(customer->getId());
}

std::vector<LevelHistory> MembershipService::getLevelHistory(Customer* customer) {
    return membershipDAO.getLevelHistory(customer->getId());
}

int MembershipService::getNormalMemberCount() {
    return membershipDAO.getNormalMemberCount();
}

int MembershipService::getSilverMemberCount() {
    return membershipDAO.getSilverMemberCount();
}

int MembershipService::getGoldMemberCount() {
    return membershipDAO.getGoldMemberCount();
}

int MembershipService::getVIPMemberCount() {
    return membershipDAO.getVIPMemberCount();
}