#ifndef FOODITEM_H
#define FOODITEM_H

#include "MenuItem.h"

class FoodItem : public MenuItem {
private:
    int cookTime;

public:
    FoodItem();
    FoodItem(int id, const std::string& name,
             const std::string& description,
             double basePrice, bool available,
             bool specialItem, int cookTime);

             
    int getCookTime() const;
    void setCookTime(int cookTime);

    double calculatePrice() const override;
    void showDetails() const override;
};

#endif