#include "CustomerMenu.h"

#include <iostream>

CustomerMenu::CustomerMenu(
    AuthService& authService,
    RestaurantService& restaurantService,
    CartService& cartService,
    OrderService& orderService,
    MembershipService& membershipService,
    int customerId)

    : authService(authService),
      restaurantService(restaurantService),
      cartService(cartService),
      orderService(orderService),
      membershipService(membershipService),
      customerId(customerId) {
}

void CustomerMenu::show() {

    int choice;

    do {

        std::cout << "\n========== CUSTOMER MENU ==========\n";

        std::cout << "1. Profile\n";
        std::cout << "2. Restaurants\n";
        std::cout << "3. Restaurant Menu\n";
        std::cout << "4. Add Item To Cart\n";
        std::cout << "5. Remove Item From Cart\n";
        std::cout << "6. Change Quantity\n";
        std::cout << "7. Show Cart\n";
        std::cout << "8. Checkout\n";
        std::cout << "9. My Orders\n";
        std::cout << "10. My Badges\n";
        std::cout << "11. Level History\n";
        std::cout << "12. My Coupons\n";
        std::cout << "0. Logout\n";

        std::cout << "\nChoice: ";
        std::cin >> choice;

        switch (choice) {

        case 1:
            showProfile();
            break;

        case 2:
            showRestaurants();
            break;

        case 3:
            showRestaurantMenu();
            break;

        case 4:
            addItemToCart();
            break;

        case 5:
            removeItemFromCart();
            break;

        case 6:
            changeItemQuantity();
            break;

        case 7:
            showCart();
            break;

        case 8:
            checkout();
            break;

        case 9:
            showOrders();
            break;

        case 10:
            showBadges();
            break;

        case 11:
            showLevelHistory();
            break;

        case 12:
            showCoupons();
            break;

        case 0:
            break;

        default:
            std::cout << "Invalid choice.\n";
        }

    } while (choice != 0);
}
void CustomerMenu::showProfile() {

    Customer* customer =
        authService.getCustomer(customerId);

    if (customer == nullptr) {
        return;
    }

    std::cout << "\n========== PROFILE ==========\n";

    std::cout << "Name: "
              << customer->getName()
              << '\n';

    std::cout << "Phone: "
              << customer->getPhone()
              << '\n';

    std::cout << "Level: "
              << customer->getMembershipLevel()
                     ->getLevelName()
              << '\n';

    std::cout << "Points: "
              << customer->getLoyaltyPoints()
              << '\n';

    std::cout << "Remaining Points: "
              << membershipService
                     .getRemainingPoints(customerId)
              << '\n';

    std::cout << "Coupons: "
              << customer->getCouponCount()
              << '\n';

    delete customer;
}

void CustomerMenu::showRestaurants() {

    restaurantService.showRestaurants();
}

void CustomerMenu::showRestaurantMenu() {

    int restaurantId;

    std::cout << "Restaurant ID: ";
    std::cin >> restaurantId;

    restaurantService.showMenu(
        restaurantId
    );
}

void CustomerMenu::addItemToCart() {

    int menuItemId;
    int quantity;

    std::cout << "Menu Item ID: ";
    std::cin >> menuItemId;

    std::cout << "Quantity: ";
    std::cin >> quantity;

    if (cartService.addItem(
            customerId,
            menuItemId,
            quantity)) {

        std::cout
            << "Added successfully.\n";
    }
    else {

        std::cout
            << "Operation failed.\n";
    }
}

void CustomerMenu::removeItemFromCart() {

    int menuItemId;

    std::cout << "Menu Item ID: ";
    std::cin >> menuItemId;

    if (cartService.removeItem(
            customerId,
            menuItemId)) {

        std::cout
            << "Removed successfully.\n";
    }
    else {

        std::cout
            << "Operation failed.\n";
    }
}
void CustomerMenu::changeItemQuantity() {

    int menuItemId;
    int quantity;

    std::cout << "Menu Item ID: ";
    std::cin >> menuItemId;

    std::cout << "New Quantity: ";
    std::cin >> quantity;

    if (cartService.updateQuantity(
            customerId,
            menuItemId,
            quantity)) {

        std::cout
            << "Quantity updated successfully.\n";
    }
    else {

        std::cout
            << "Operation failed.\n";
    }
}

void CustomerMenu::showCart() {

    cartService.showCart(customerId);
}

void CustomerMenu::checkout() {

    if (orderService.checkout(customerId)) {

        std::cout
            << "Order placed successfully.\n";
    }
    else {

        std::cout
            << "Checkout failed.\n";
    }
}

void CustomerMenu::showOrders() {

    orderService.showCustomerOrders(
        customerId
    );
}

void CustomerMenu::showBadges() {

    membershipService.showBadges(
        customerId
    );
}

void CustomerMenu::showLevelHistory() {

    membershipService.showLevelHistory(
        customerId
    );
}

void CustomerMenu::showCoupons() {

    membershipService.showCoupons(
        customerId
    );
}