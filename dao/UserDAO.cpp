#include "UserDAO.h"

#include "../models/membership/MembershipFactory.h"

#include <memory>

UserDAO::UserDAO(DatabaseManager& databaseManager)
    : databaseManager(databaseManager) {
}

bool UserDAO::phoneExists(const std::string& phone) {
    sql::Connection* connection = databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "SELECT COUNT(*) FROM users WHERE phone = ?"
        )
    );

    statement->setString(1, phone);

    std::unique_ptr<sql::ResultSet> result(
        statement->executeQuery()
    );

    result->next();

    return result->getInt(1) > 0;
}

bool UserDAO::addCustomer(const Customer& customer) {
    sql::Connection* connection = databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "INSERT INTO users("
            "name,"
            "phone,"
            "role,"
            "loyalty_points,"
            "membership_level,"
            "successful_orders,"
            "coupon_count"
            ") VALUES(?,?,?,?,?,?,?)"
        )
    );

    statement->setString(1, customer.getName());
    statement->setString(2, customer.getPhone());
    statement->setString(3, "Customer");

    statement->setInt(
        4,customer.getLoyaltyPoints()
    );

    statement->setString(
        5,customer.getMembershipLevel()->getLevelName()
    );

    statement->setInt(
        6,customer.getSuccessfulOrders()
    );

    statement->setInt(
        7,customer.getCouponCount()
    );

    return statement->executeUpdate() > 0;
}

Customer* UserDAO::getCustomerById(int customerId) {
    sql::Connection* connection = databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "SELECT * FROM users "
            "WHERE id = ? "
            "AND role = 'Customer'"
        )
    );

    statement->setInt(1, customerId);

    std::unique_ptr<sql::ResultSet> result(
        statement->executeQuery()
    );

    if (!result->next()) {
        return nullptr;
    }

    Customer* customer = new Customer(
        result->getInt("id"),
        result->getString("name"),
        result->getString("phone")
    );

    customer->setLoyaltyPoints(
        result->getInt("loyalty_points")
    );

    customer->setSuccessfulOrders(
        result->getInt("successful_orders")
    );

    customer->setCouponCount(
        result->getInt("coupon_count")
    );

    customer->setMembershipLevel(
        MembershipFactory::createLevel(
            result->getString("membership_level")
        )
    );

    return customer;
}

RestaurantAdmin* UserDAO::getRestaurantAdminById(int adminId) {
    sql::Connection* connection = databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "SELECT * FROM users "
            "WHERE id = ? "
            "AND role = 'RestaurantAdmin'"
        )
    );

    statement->setInt(1, adminId);

    std::unique_ptr<sql::ResultSet> result(
        statement->executeQuery()
    );

    if (!result->next()) {
        return nullptr;
    }

    return new RestaurantAdmin(
        result->getInt("id"),
        result->getString("name"),
        result->getString("phone")
    );
}

SystemAdmin* UserDAO::getSystemAdminById(int adminId) {
    sql::Connection* connection = databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "SELECT * FROM users "
            "WHERE id = ? "
            "AND role = 'SystemAdmin'"
        )
    );

    statement->setInt(1, adminId);

    std::unique_ptr<sql::ResultSet> result(
        statement->executeQuery()
    );

    if (!result->next()) {
        return nullptr;
    }

    return new SystemAdmin(
        result->getInt("id"),
        result->getString("name"),
        result->getString("phone")
    );
}

User* UserDAO::getUserByPhone(const std::string& phone) {
    sql::Connection* connection = databaseManager.getConnection();

    std::unique_ptr<sql::PreparedStatement> statement(
        connection->prepareStatement(
            "SELECT * FROM users WHERE phone = ?"
        )
    );

    statement->setString(1, phone);

    std::unique_ptr<sql::ResultSet> result(
        statement->executeQuery()
    );

    if (!result->next()) {
        return nullptr;
    }

    std::string role = result->getString("role");

    if (role == "Customer") {
        Customer* customer = new Customer(
            result->getInt("id"),
            result->getString("name"),
            result->getString("phone")
        );

        customer->setLoyaltyPoints(
            result->getInt("loyalty_points")
        );

        customer->setSuccessfulOrders(
            result->getInt("successful_orders")
        );

        customer->setCouponCount(
            result->getInt("coupon_count")
        );

        customer->setMembershipLevel(
            MembershipFactory::createLevel(
                result->getString("membership_level")
            )
        );

        return customer;
    }

    if (role == "RestaurantAdmin") {
        return new RestaurantAdmin(
            result->getInt("id"),
            result->getString("name"),
            result->getString("phone")
        );
    }

    return new SystemAdmin(
        result->getInt("id"),
        result->getString("name"),
        result->getString("phone")
    );
}