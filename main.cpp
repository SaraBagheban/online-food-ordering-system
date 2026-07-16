#include "database/DatabaseManager.h"

#include "dao/UserDAO.h"
#include "dao/RestaurantDAO.h"
#include "dao/MenuItemDAO.h"
#include "dao/CartDAO.h"
#include "dao/OrderDAO.h"
#include "dao/MembershipDAO.h"

#include "services/AuthService.h"
#include "services/RestaurantService.h"
#include "services/CartService.h"
#include "services/OrderService.h"
#include "services/MembershipService.h"

#include "ui/CustomerMenu.h"
#include "ui/RestaurantAdminMenu.h"
#include "ui/SystemAdminMenu.h"

#include "models/users/User.h"
#include "models/users/Customer.h"
#include "models/users/RestaurantAdmin.h"
#include "models/users/SystemAdmin.h"

#include <iostream>

int main() {

    try {

        DatabaseManager databaseManager;
        databaseManager.connect();

        UserDAO userDAO(databaseManager);
        RestaurantDAO restaurantDAO(databaseManager);
        MenuItemDAO menuItemDAO(databaseManager);
        CartDAO cartDAO(databaseManager);
        OrderDAO orderDAO(databaseManager);
        MembershipDAO membershipDAO(databaseManager);

        AuthService authService(
            userDAO
        );

        RestaurantService restaurantService(
            restaurantDAO,
            menuItemDAO,
            membershipDAO
        );

        CartService cartService(
            cartDAO,
            menuItemDAO
        );

        OrderService orderService(
            orderDAO,
            cartDAO,
            membershipDAO
        );

        MembershipService membershipService(
            membershipDAO
        );

        while (true) {

            std::cout
                << "\n=================================\n";
            std::cout
                << " ONLINE FOOD ORDERING SYSTEM\n";
            std::cout
                << "=================================\n";

            std::cout
                << "1. Login\n";
            std::cout
                << "2. Register Customer\n";
            std::cout
                << "0. Exit\n";

            int choice;

            std::cout
                << "\nChoice: ";

            std::cin >> choice;

            switch (choice) {

            case 1: {

                User* user =
                    authService.login();

                if (user == nullptr) {

                    std::cout
                        << "Login failed.\n";

                    break;
                }

                if (dynamic_cast<Customer*>(user)) {

                    CustomerMenu customerMenu(
                        authService,
                        restaurantService,
                        cartService,
                        orderService,
                        membershipService,
                        user->getId()
                    );

                    customerMenu.show();
                }

                else if (
                    dynamic_cast<RestaurantAdmin*>(user)
                ) {

                    RestaurantAdminMenu
                        restaurantAdminMenu(

                            restaurantService,
                            orderService,
                            user->getId()
                        );

                    restaurantAdminMenu.show();
                }

                else if (
                    dynamic_cast<SystemAdmin*>(user)
                ) {

                    SystemAdminMenu
                        systemAdminMenu(

                            authService,
                            restaurantService,
                            membershipService,
                            user->getId()
                        );

                    systemAdminMenu.show();
                }

                delete user;

                break;
            }

            case 2:

                authService.registerCustomer();

                break;

            case 0:

                databaseManager.disconnect();

                std::cout
                    << "Goodbye!\n";

                return 0;

            default:

                std::cout
                    << "Invalid choice.\n";
            }
        }
    }

    catch (const sql::SQLException& exception) {

        std::cout
            << "Database Error:\n"
            << exception.what()
            << '\n';
    }

    catch (const std::exception& exception) {

        std::cout
            << "Error:\n"
            << exception.what()
            << '\n';
    }

    return 0;
}