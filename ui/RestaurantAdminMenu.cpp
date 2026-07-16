#include "RestaurantAdminMenu.h"

#include <iostream>

RestaurantAdminMenu::RestaurantAdminMenu(
    RestaurantService& restaurantService,
    OrderService& orderService,
    int adminId)

    : restaurantService(restaurantService),
      orderService(orderService),
      adminId(adminId) {
}

void RestaurantAdminMenu::show() {

    int choice;

    do {

        std::cout
            << "\n====== RESTAURANT ADMIN MENU ======\n";

        std::cout << "1. Restaurant Information\n";
        std::cout << "2. Edit Restaurant Information\n";
        std::cout << "3. Show Menu\n";
        std::cout << "4. Add Menu Item\n";
        std::cout << "5. Edit Menu Item\n";
        std::cout << "6. Remove Menu Item\n";
        std::cout << "7. Change Availability\n";
        std::cout << "8. Change Special Status\n";
        std::cout << "9. Show Orders\n";
        std::cout << "10. Update Order Status\n";
        std::cout << "0. Logout\n";

        std::cout << "\nChoice: ";
        std::cin >> choice;

        switch (choice) {

        case 1:
            showRestaurantInformation();
            break;

        case 2:
            editRestaurantInformation();
            break;

        case 3:
            showMenu();
            break;

        case 4:
            addMenuItem();
            break;

        case 5:
            editMenuItem();
            break;

        case 6:
            removeMenuItem();
            break;

        case 7:
            changeAvailability();
            break;

        case 8:
            changeSpecialStatus();
            break;

        case 9:
            showOrders();
            break;

        case 10:
            updateOrderStatus();
            break;

        case 0:
            break;

        default:
            std::cout << "Invalid choice.\n";
        }

    } while (choice != 0);
}
void RestaurantAdminMenu::showRestaurantInformation() {

    restaurantService.showRestaurantInfo(
        adminId
    );
}

void RestaurantAdminMenu::editRestaurantInformation() {

    restaurantService.editRestaurantInfo(
        adminId
    );
}

void RestaurantAdminMenu::showMenu() {

    restaurantService.showMenuByAdmin(
        adminId
    );
}

void RestaurantAdminMenu::addMenuItem() {

    restaurantService.addMenuItem(
        adminId
    );
}

void RestaurantAdminMenu::editMenuItem() {

    restaurantService.editMenuItem(
        adminId
    );
}

void RestaurantAdminMenu::removeMenuItem() {

    int menuItemId;

    std::cout << "Menu Item ID: ";
    std::cin >> menuItemId;

    if (restaurantService.removeMenuItem(
            adminId,
            menuItemId)) {

        std::cout
            << "Menu item removed successfully.\n";
    }
    else {

        std::cout
            << "Operation failed.\n";
    }
}
void RestaurantAdminMenu::changeAvailability() {

    int menuItemId;

    std::cout << "Menu Item ID: ";
    std::cin >> menuItemId;

    restaurantService.changeAvailability(
        adminId,
        menuItemId
    );
}

void RestaurantAdminMenu::changeSpecialStatus() {

    int menuItemId;

    std::cout << "Menu Item ID: ";
    std::cin >> menuItemId;

    restaurantService.changeSpecialStatus(
        adminId,
        menuItemId
    );
}

void RestaurantAdminMenu::showOrders() {

    orderService.showRestaurantOrders(
        adminId
    );
}

void RestaurantAdminMenu::updateOrderStatus() {

    int orderId;

    std::cout << "Order ID: ";
    std::cin >> orderId;

    orderService.updateOrderStatus(
        adminId,
        orderId
    );
}
