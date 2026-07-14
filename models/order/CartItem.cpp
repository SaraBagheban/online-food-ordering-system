#include "CartItem.h"

CartItem::CartItem() : item(nullptr), itemName(""),
      quantity(0), unitPrice(0) {
}

CartItem::CartItem(MenuItem* item, int quantity) : item(item),
      itemName(item->getName()), quantity(quantity), unitPrice(item->calculatePrice()) {
}



MenuItem* CartItem::getItem() const {
    return item;
}

std::string CartItem::getItemName() const {
    return itemName;
}

int CartItem::getQuantity() const {
    return quantity;
}

double CartItem::getUnitPrice() const {
    return unitPrice;
}



void CartItem::setItem(MenuItem* item) {
    this->item = item;
}

void CartItem::setItemName(const std::string& itemName) {
    this->itemName = itemName;
}

void CartItem::setQuantity(int quantity) {
    this->quantity = quantity;
}

void CartItem::setUnitPrice(double unitPrice) {
    this->unitPrice = unitPrice;
}



double CartItem::getTotalPrice() const {
    return unitPrice * quantity;
}