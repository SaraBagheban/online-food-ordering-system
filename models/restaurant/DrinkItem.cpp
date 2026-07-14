#include "DrinkItem.h"

#include <iostream>

DrinkItem::DrinkItem() : MenuItem(), volume(0) {
}

DrinkItem::DrinkItem(int id, const std::string& name,
                     const std::string& description,
                     double basePrice, bool available,
                     double volume)
    : MenuItem(id, name, description, basePrice, available),
      volume(volume) {
}



double DrinkItem::getVolume() const {
    return volume;
}

void DrinkItem::setVolume(double volume) {
    this->volume = volume;
}

double DrinkItem::calculatePrice() const {
    return getBasePrice() * volume;
}

void DrinkItem::showDetails() const {
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Description: " << getDescription() << std::endl;
    std::cout << "Base Cup Price: " << getBasePrice() << std::endl;
    std::cout << "Volume: " << volume << " x standard cup size" << std::endl;
    std::cout << "Calculated Price: " << calculatePrice() << std::endl;
    std::cout << "Available: " << (getAvailable() ? "Yes" : "No") << std::endl;
}