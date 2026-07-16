#ifndef CARTDAO_H
#define CARTDAO_H

#include "../database/DatabaseManager.h"
#include "../models/order/Cart.h"

class CartDAO {
private:
    DatabaseManager& databaseManager;

public:
    explicit CartDAO(DatabaseManager& databaseManager);

    bool addItem(int customerId, int menuItemId, int quantity);
    bool removeItem(int customerId, int menuItemId);
    bool updateQuantity(int customerId, int menuItemId, int quantity);
    bool clearCart(int customerId);

    Cart* getCart(int customerId);
    bool isCartEmpty(int customerId);
    double calculateSubtotal(int customerId);

private:
    int getCartId(int customerId);
    bool createCart(int customerId);
};

#endif