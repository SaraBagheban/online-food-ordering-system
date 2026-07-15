#include "CartService.h"

CartService::CartService() {
}

bool CartService::addItem(Customer* customer, int menuItemId, int quantity) {

    MenuItem* item = menuItemDAO.getMenuItem(menuItemId);

    if (item == nullptr) {
        return false;
    }

    if (!item->getAvailable()) {
        return false;
    }

    if (item->isSpecialItem() &&
        !customer->getMembershipLevel()->canAccessSpecialMenu()) {
        return false;
    }

    return cartDAO.addItem(customer->getId(), menuItemId, quantity);
}

bool CartService::removeItem(Customer* customer, int menuItemId) {

    return cartDAO.removeItem(customer->getId(), menuItemId);
}

bool CartService::updateQuantity(Customer* customer, int menuItemId, int quantity) {

    return cartDAO.updateQuantity(customer->getId(), menuItemId, quantity);
}

bool CartService::clearCart(Customer* customer) {

    return cartDAO.clearCart(customer->getId());
}

Cart* CartService::getCart(Customer* customer) {

    return cartDAO.getCart(customer->getId());
}

bool CartService::isCartEmpty(Customer* customer) {

    return cartDAO.isCartEmpty(customer->getId());
}

double CartService::calculateSubtotal(Customer* customer) {

    return cartDAO.calculateSubtotal(customer->getId());
}