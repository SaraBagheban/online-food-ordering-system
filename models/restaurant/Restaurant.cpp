#include "Restaurant.h"

Restaurant::Restaurant() : id(0), name(""), address(""), phone(""),
      description(""), prepTime(0), isActive(true) {
}

Restaurant::Restaurant(int id, const std::string& name,
                       const std::string& address,
                       const std::string& phone,
                       const std::string& description,
                       int prepTime, bool isActive)
    : id(id), name(name), address(address),
      phone(phone), description(description),
      prepTime(prepTime), isActive(isActive) {
}



int Restaurant::getId() const {
    return id;
}

std::string Restaurant::getName() const {
    return name;
}

std::string Restaurant::getAddress() const {
    return address;
}

std::string Restaurant::getPhone() const {
    return phone;
}

std::string Restaurant::getDescription() const {
    return description;
}

int Restaurant::getPrepTime() const {
    return prepTime;
}

bool Restaurant::getIsActive() const {
    return isActive;
}



void Restaurant::setId(int id) {
    this->id = id;
}

void Restaurant::setName(const std::string& name) {
    this->name = name;
}

void Restaurant::setAddress(const std::string& address) {
    this->address = address;
}

void Restaurant::setPhone(const std::string& phone) {
    this->phone = phone;
}

void Restaurant::setDescription(const std::string& description) {
    this->description = description;
}

void Restaurant::setPrepTime(int prepTime) {
    this->prepTime = prepTime;
}

void Restaurant::setIsActive(bool isActive) {
    this->isActive = isActive;
}