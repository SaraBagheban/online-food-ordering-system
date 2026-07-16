#include "SystemAdminMenu.h"

#include <iostream>

SystemAdminMenu::SystemAdminMenu(
    AuthService& authService,
    RestaurantService& restaurantService,
    MembershipService& membershipService,
    int adminId)

    : authService(authService),
      restaurantService(restaurantService),
      membershipService(membershipService),
      adminId(adminId) {
}

void SystemAdminMenu::show() {

    int choice;

    do {

        std::cout
            << "\n========== SYSTEM ADMIN MENU ==========\n";

        std::cout << "1. Register Restaurant Admin\n";
        std::cout << "2. Register Restaurant\n";
        std::cout << "3. Show Restaurants\n";
        std::cout << "4. Activate Restaurant\n";
        std::cout << "5. Deactivate Restaurant\n";
        std::cout << "6. Membership Statistics\n";
        std::cout << "7. Show Users\n";
        std::cout << "8. System Statistics\n";
        std::cout << "0. Logout\n";

        std::cout << "\nChoice: ";
        std::cin >> choice;

        switch (choice) {

        case 1:
            registerRestaurantAdmin();
            break;

        case 2:
            registerRestaurant();
            break;

        case 3:
            showAllRestaurants();
            break;

        case 4:
            activateRestaurant();
            break;

        case 5:
            deactivateRestaurant();
            break;

        case 6:
            showMembershipStatistics();
            break;

        case 7:
            showUsers();
            break;

        case 8:
            showSystemStatistics();
            break;

        case 0:
            break;

        default:
            std::cout << "Invalid choice.\n";
        }

    } while (choice != 0);
}
void SystemAdminMenu::registerRestaurantAdmin() {

    authService.registerRestaurantAdmin();
}

void SystemAdminMenu::registerRestaurant() {

    restaurantService.registerRestaurant();
}

void SystemAdminMenu::showAllRestaurants() {

    restaurantService.showAllRestaurants();
}

void SystemAdminMenu::activateRestaurant() {

    int restaurantId;

    std::cout << "Restaurant ID: ";
    std::cin >> restaurantId;

    if (restaurantService.activateRestaurant(
            restaurantId)) {

        std::cout
            << "Restaurant activated successfully.\n";
    }
    else {

        std::cout
            << "Operation failed.\n";
    }
}

void SystemAdminMenu::deactivateRestaurant() {

    int restaurantId;

    std::cout << "Restaurant ID: ";
    std::cin >> restaurantId;

    if (restaurantService.deactivateRestaurant(
            restaurantId)) {

        std::cout
            << "Restaurant deactivated successfully.\n";
    }
    else {

        std::cout
            << "Operation failed.\n";
    }
}
void SystemAdminMenu::showMembershipStatistics() {

    membershipService.showMembershipStatistics();
}

void SystemAdminMenu::showUsers() {

    authService.showUsers();
}

void SystemAdminMenu::showSystemStatistics() {

    restaurantService.showSystemStatistics();
}