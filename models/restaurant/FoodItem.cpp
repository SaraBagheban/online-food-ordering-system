#include "FoodItem.h"

#include <iostream>

FoodItem::FoodItem() : MenuItem(), cookTime(0) {
}

FoodItem::FoodItem(int id, const std::string& name,
                   const std::string& description,
                   double basePrice, bool available,
                   bool specialItem, int cookTime)
    : MenuItem(id, name, description, basePrice, available, specialItem),
      cookTime(cookTime) {
}



int FoodItem::getCookTime() const {
    return cookTime;
}

void FoodItem::setCookTime(int cookTime) {
    this->cookTime = cookTime;
}


double FoodItem::calculatePrice() const {
    double extraCookFactor = (cookTime - 15) / 15.0;

    if (extraCookFactor < 0) {
        extraCookFactor = 0;
    }

    const double pricePer15Minutes = 0.05;

    return getBasePrice() * (1 + extraCookFactor * pricePer15Minutes);
}

void FoodItem::showDetails() const {
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Description: " << getDescription() << std::endl;
    std::cout << "Special Item: " << (isSpecialItem() ? "Yes" : "No") << std::endl;
    std::cout << "Cook Time: " << cookTime << " min" << std::endl;
    std::cout << "Price: " << calculatePrice() << std::endl;
    std::cout << "Available: " << (getAvailable() ? "Yes" : "No") << std::endl;
}