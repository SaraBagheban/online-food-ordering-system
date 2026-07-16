#ifndef USERDAO_H
#define USERDAO_H

#include "../database/DatabaseManager.h"
#include "../models/users/User.h"
#include "../models/users/Customer.h"
#include "../models/users/RestaurantAdmin.h"
#include "../models/users/SystemAdmin.h"

#include <string>
#include <vector>

class UserDAO {
private:
    DatabaseManager& databaseManager;

public:
    explicit UserDAO(DatabaseManager& databaseManager);

    User* getUserByPhone(const std::string& phone);
    Customer* getCustomerById(int customerId);
    RestaurantAdmin* getRestaurantAdminById(int adminId);
    SystemAdmin* getSystemAdminById(int adminId);

    bool addCustomer(const Customer& customer);

    bool phoneExists(const std::string& phone);
};

#endif