#ifndef CART_H
#define CART_H

#include "CartItem.h"

#include <vector>

class Cart {
private:
    std::vector<CartItem> items;

public:
    Cart();

    void addItem(MenuItem* item, int quantity);
    void removeItem(int index);
    void clearCart();

    const std::vector<CartItem>& getItems() const;

    double getCartPrice() const;

    bool isEmpty() const;

    void showCart() const;
};

#endif