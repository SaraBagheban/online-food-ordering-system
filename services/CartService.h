#ifndef CARTSERVICE_H
#define CARTSERVICE_H

#include "../dao/CartDAO.h"
#include "../dao/MenuItemDAO.h"
#include "../models/users/Customer.h"
#include "../models/order/Cart.h"

class CartService {
private:
    CartDAO cartDAO;
    MenuItemDAO menuItemDAO;

public:
    CartService();

    bool addItem(Customer* customer, int menuItemId, int quantity);

    bool removeItem(Customer* customer, int menuItemId);

    bool updateQuantity(Customer* customer, int menuItemId, int quantity);

    bool clearCart(Customer* customer);

    Cart* getCart(Customer* customer);

    bool isCartEmpty(Customer* customer);

    double calculateSubtotal(Customer* customer);
};

#endif