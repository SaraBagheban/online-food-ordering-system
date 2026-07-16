#ifndef CUSTOMERMENU_H
#define CUSTOMERMENU_H

#include "../services/AuthService.h"
#include "../services/RestaurantService.h"
#include "../services/CartService.h"
#include "../services/OrderService.h"
#include "../services/MembershipService.h"

class CustomerMenu {
private:
    AuthService& authService;
    RestaurantService& restaurantService;
    CartService& cartService;
    OrderService& orderService;
    MembershipService& membershipService;

    int customerId;

public:
    CustomerMenu(AuthService& authService,
                 RestaurantService& restaurantService,
                 CartService& cartService,
                 OrderService& orderService,
                 MembershipService& membershipService,
                 int customerId);

    void show();

private:
    void showProfile();

    void showRestaurants();

    void showRestaurantMenu();

    void addItemToCart();

    void removeItemFromCart();

    void changeItemQuantity();

    void showCart();

    void checkout();

    void showOrders();

    void showBadges();

    void showLevelHistory();

    void showCoupons();
};

#endif