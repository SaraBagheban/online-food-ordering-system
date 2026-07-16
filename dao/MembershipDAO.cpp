#include "MembershipDAO.h"

#include <memory>

MembershipDAO::MembershipDAO(
    DatabaseManager& databaseManager)
    : databaseManager(databaseManager) {
}

bool MembershipDAO::addPoints(
    int customerId,
    int points) {

    sql::Connection* connection =
        databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "UPDATE users "
            "SET loyalty_points = "
            "loyalty_points + ? "
            "WHERE id=?"
        )
    );

    statement->setInt(1, points);
    statement->setInt(2, customerId);

    return statement->executeUpdate() > 0;
}

bool MembershipDAO::removePoints(
    int customerId,
    int points) {

    sql::Connection* connection =
        databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "UPDATE users "
            "SET loyalty_points = "
            "GREATEST(0, loyalty_points - ?) "
            "WHERE id=?"
        )
    );

    statement->setInt(1, points);
    statement->setInt(2, customerId);

    return statement->executeUpdate() > 0;
}

bool MembershipDAO::addLevelHistory(
    const LevelHistory& history) {

    sql::Connection* connection =
        databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "INSERT INTO level_history("
            "customer_id,"
            "old_level,"
            "new_level,"
            "points,"
            "successful_orders"
            ") VALUES(?,?,?,?,?)"
        )
    );

    statement->setInt(
        1,
        history.getCustomerId()
    );

    statement->setString(
        2,
        history.getOldLevel()
    );

    statement->setString(
        3,
        history.getNewLevel()
    );

    statement->setInt(
        4,
        history.getPoints()
    );

    statement->setInt(
        5,
        history.getSuccessfulOrders()
    );

    return statement->executeUpdate() > 0;
}
bool MembershipDAO::checkLevelUpgrade(
    int customerId) {

    sql::Connection* connection =
        databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "SELECT loyalty_points "
            "FROM users "
            "WHERE id=?"
        )
    );

    statement->setInt(1, customerId);

    std::unique_ptr<sql::ResultSet> result(
        statement->executeQuery()
    );

    if (!result->next()) {
        return false;
    }

    int points =
        result->getInt("loyalty_points");

    std::string newLevel = "Normal";

    if (points >= 5000) {
        newLevel = "VIP";
    }
    else if (points >= 2500) {
        newLevel = "Gold";
    }
    else if (points >= 1000) {
        newLevel = "Silver";
    }

    std::unique_ptr<sql::PreparedStatement> update(
        connection->prepareStatement(
            "UPDATE users "
            "SET membership_level=? "
            "WHERE id=?"
        )
    );

    update->setString(1, newLevel);
    update->setInt(2, customerId);

    return update->executeUpdate() > 0;
}

bool MembershipDAO::checkLevelDowngrade(
    int customerId) {

    return checkLevelUpgrade(customerId);
}

bool MembershipDAO::assignMonthlyCoupons(
    int customerId) {

    sql::Connection* connection =
        databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> levelStatement(
        connection->prepareStatement(
            "SELECT membership_level "
            "FROM users "
            "WHERE id=?"
        )
    );

    levelStatement->setInt(1, customerId);

    std::unique_ptr<sql::ResultSet> result(
        levelStatement->executeQuery()
    );

    if (!result->next()) {
        return false;
    }

    std::string level =
        result->getString("membership_level");

    int couponCount = 0;
    double amount = 0.0;

    if (level == "Silver") {
        couponCount = 1;
        amount = 30;
    }
    else if (level == "Gold") {
        couponCount = 2;
        amount = 50;
    }
    else if (level == "VIP") {
        couponCount = 3;
        amount = 80;
    }

    for (int i = 0; i < couponCount; i++) {

        std::unique_ptr<sql::PreparedStatement> insert(
            connection->prepareStatement(
                "INSERT INTO coupons("
                "customer_id,"
                "discount_amount"
                ") VALUES(?,?)"
            )
        );

        insert->setInt(1, customerId);
        insert->setDouble(2, amount);

        insert->executeUpdate();
    }

    return true;
}
bool MembershipDAO::checkBadges(
    int customerId) {

    sql::Connection* connection =
        databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> userStatement(
        connection->prepareStatement(
            "SELECT successful_orders "
            "FROM users "
            "WHERE id=?"
        )
    );

    userStatement->setInt(1, customerId);

    std::unique_ptr<sql::ResultSet> userResult(
        userStatement->executeQuery()
    );

    if (!userResult->next()) {
        return false;
    }

    int successfulOrders =
        userResult->getInt("successful_orders");

    int badgeId = -1;

    if (successfulOrders >= 100) {
        badgeId = 3;
    }
    else if (successfulOrders >= 50) {
        badgeId = 2;
    }
    else if (successfulOrders >= 10) {
        badgeId = 1;
    }

    if (badgeId == -1) {
        return true;
    }

    std::unique_ptr<sql::PreparedStatement> checkStatement(
        connection->prepareStatement(
            "SELECT * "
            "FROM customer_badges "
            "WHERE customer_id=? "
            "AND badge_id=?"
        )
    );

    checkStatement->setInt(1, customerId);
    checkStatement->setInt(2, badgeId);

    std::unique_ptr<sql::ResultSet> checkResult(
        checkStatement->executeQuery()
    );

    if (checkResult->next()) {
        return true;
    }

    std::unique_ptr<sql::PreparedStatement> insertStatement(
        connection->prepareStatement(
            "INSERT INTO customer_badges("
            "customer_id,"
            "badge_id"
            ") VALUES(?,?)"
        )
    );

    insertStatement->setInt(1, customerId);
    insertStatement->setInt(2, badgeId);

    return insertStatement->executeUpdate() > 0;
}

int MembershipDAO::getRemainingPoints(
    int customerId) {

    sql::Connection* connection =
        databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "SELECT loyalty_points,"
            "membership_level "
            "FROM users "
            "WHERE id=?"
        )
    );

    statement->setInt(1, customerId);

    std::unique_ptr<sql::ResultSet> result(
        statement->executeQuery()
    );

    if (!result->next()) {
        return 0;
    }

    int points =
        result->getInt("loyalty_points");

    std::string level =
        result->getString("membership_level");

    if (level == "Normal") {
        return 1000 - points;
    }

    if (level == "Silver") {
        return 2500 - points;
    }

    if (level == "Gold") {
        return 5000 - points;
    }

    return 0;
}
std::vector<Badge>
MembershipDAO::getBadges(
    int customerId) {

    sql::Connection* connection =
        databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "SELECT b.id, b.name, b.description "
            "FROM badges b "
            "INNER JOIN customer_badges cb "
            "ON b.id = cb.badge_id "
            "WHERE cb.customer_id=? "
            "ORDER BY cb.earned_date"
        )
    );

    statement->setInt(1, customerId);

    std::unique_ptr<sql::ResultSet> result(
        statement->executeQuery()
    );

    std::vector<Badge> badges;

    while (result->next()) {

        badges.emplace_back(
            result->getInt("id"),
            result->getString("name"),
            result->getString("description")
        );
    }

    return badges;
}

std::vector<LevelHistory>
MembershipDAO::getLevelHistory(
    int customerId) {

    sql::Connection* connection =
        databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "SELECT * "
            "FROM level_history "
            "WHERE customer_id=? "
            "ORDER BY change_date DESC"
        )
    );

    statement->setInt(1, customerId);

    std::unique_ptr<sql::ResultSet> result(
        statement->executeQuery()
    );

    std::vector<LevelHistory> history;

    while (result->next()) {

        history.emplace_back(
            result->getInt("customer_id"),
            result->getString("old_level"),
            result->getString("new_level"),
            result->getInt("points"),
            result->getInt("successful_orders"),
            result->getString("change_date")
        );
    }

    return history;
}
int MembershipDAO::getNormalMemberCount() {

    sql::Connection* connection =
        databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "SELECT COUNT(*) "
            "FROM users "
            "WHERE membership_level='Normal'"
        )
    );

    std::unique_ptr<sql::ResultSet> result(
        statement->executeQuery()
    );

    result->next();

    return result->getInt(1);
}

int MembershipDAO::getSilverMemberCount() {

    sql::Connection* connection =
        databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "SELECT COUNT(*) "
            "FROM users "
            "WHERE membership_level='Silver'"
        )
    );

    std::unique_ptr<sql::ResultSet> result(
        statement->executeQuery()
    );

    result->next();

    return result->getInt(1);
}

int MembershipDAO::getGoldMemberCount() {

    sql::Connection* connection =
        databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "SELECT COUNT(*) "
            "FROM users "
            "WHERE membership_level='Gold'"
        )
    );

    std::unique_ptr<sql::ResultSet> result(
        statement->executeQuery()
    );

    result->next();

    return result->getInt(1);
}

int MembershipDAO::getVIPMemberCount() {

    sql::Connection* connection =
        databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "SELECT COUNT(*) "
            "FROM users "
            "WHERE membership_level='VIP'"
        )
    );

    std::unique_ptr<sql::ResultSet> result(
        statement->executeQuery()
    );

    result->next();

    return result->getInt(1);
}