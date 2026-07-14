#ifndef CARTITEM_H
#define CARTITEM_H

#include <string>

#include "../restaurant/MenuItem.h"

class CartItem {
private:
    MenuItem* item;
    std::string itemName;
    int quantity;
    double unitPrice;

public:
    CartItem();
    CartItem(MenuItem* item, int quantity);

    MenuItem* getItem() const;
    std::string getItemName() const;
    int getQuantity() const;
    double getUnitPrice() const;
    double getTotalPrice() const;

    void setItem(MenuItem* item);
    void setItemName(const std::string& itemName);
    void setQuantity(int quantity);
    void setUnitPrice(double unitPrice);
};

#endif