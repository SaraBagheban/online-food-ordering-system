#include "MenuItem.h"

MenuItem::MenuItem() : id(0), name(""), description(""),
      basePrice(0), available(true) {
}

MenuItem::MenuItem(int id, const std::string& name,
                   const std::string& description,
                   double basePrice, bool available)
    : id(id), name(name), description(description),
      basePrice(basePrice), available(available) {
}

MenuItem::~MenuItem() {
}


int MenuItem::getId() const {
    return id;
}

std::string MenuItem::getName() const {
    return name;
}

std::string MenuItem::getDescription() const {
    return description;
}

double MenuItem::getBasePrice() const {
    return basePrice;
}

bool MenuItem::getAvailable() const {
    return available;
}



void MenuItem::setId(int id) {
    this->id = id;
}

void MenuItem::setName(const std::string& name) {
    this->name = name;
}

void MenuItem::setDescription(const std::string& description) {
    this->description = description;
}

void MenuItem::setBasePrice(double basePrice) {
    this->basePrice = basePrice;
}

void MenuItem::setAvailable(bool available) {
    this->available = available;
}