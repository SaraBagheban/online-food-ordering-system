#ifndef DRINKITEM_H
#define DRINKITEM_H

#include "MenuItem.h"

class DrinkItem : public MenuItem {
private:
    double volume;

public:
    DrinkItem();
    DrinkItem(int id, const std::string& name,
              const std::string& description,
              double basePrice, bool available,
              double volume);

              
    double getVolume() const;
    void setVolume(double volume);

    double calculatePrice() const override;
    void showDetails() const override;
};

#endif