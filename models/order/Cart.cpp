#include "Cart.h"

#include <iostream>

Cart::Cart() {
}

void Cart::addItem(MenuItem* item, int quantity) {

    if (!item->getAvailable()) {
        std::cout << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        std::cout << item->getName() << " is currently unavailable." << std::endl;
        std::cout << "----------------------------------------" << std::endl << std::endl;
        return;
    }

    for (int i = 0; i < items.size(); i++) {

        if (items[i].getItem() == item) {

            items[i].setQuantity(items[i].getQuantity() + quantity);
            std::cout << std::endl;
            std::cout << "----------------------------------------" << std::endl;
            std::cout << quantity << " more " << item->getName()
                      << "(s) added to cart." << std::endl;
            std::cout << "----------------------------------------" << std::endl << std::endl;

            return;
        }
    }

    items.push_back(CartItem(item, quantity));

    std::cout << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << item->getName() << " added to cart successfully." << std::endl;
    std::cout << "----------------------------------------" << std::endl << std::endl;
}

void Cart::removeItem(int index) {

    if (index >= 0 && index < items.size()) {
        items.erase(items.begin() + index);
    }
}

const std::vector<CartItem>& Cart::getItems() const {
    return items;
}

double Cart::getCartPrice() const {
    double total = 0;

    for (int i = 0; i < items.size(); i++) {
        total += items[i].getTotalPrice();
    }

    return total;
}

void Cart::clearCart() {
    items.clear();
}

bool Cart::isEmpty() const {
    return items.empty();
}

void Cart::showCart() const {

    std::cout << std::endl;
    std::cout << "============== YOUR CART ==============" << std::endl << std::endl;

    if (items.empty()) {
        std::cout << "Cart is empty." << std::endl << std::endl;
        return;
    }

    for (int i = 0; i < items.size(); i++) {

        std::cout << "----------------------------------------" << std::endl;

        std::cout << "Item " << i + 1 << std::endl;
        std::cout << "----------------------------------------" << std::endl;

        std::cout << "Name: " << items[i].getItemName() << std::endl;
        std::cout << "Quantity: " << items[i].getQuantity() << std::endl;
        std::cout << "Unit Price: " << items[i].getUnitPrice() << std::endl;
        std::cout << "Item Total: " << items[i].getTotalPrice() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "========================================" << std::endl;

    std::cout << "Cart Price: " << getCartPrice() << std::endl;

    std::cout << "========================================" << std::endl << std::endl;
}