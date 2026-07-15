#include "Badge.h"

Badge::Badge() : name(""), description("") {
}

Badge::Badge(const std::string& name, const std::string& description)
    : name(name), description(description) {
}


std::string Badge::getName() const {
    return name;
}

std::string Badge::getDescription() const {
    return description;
}

void Badge::setName(const std::string& name) {
    this->name = name;
}

void Badge::setDescription(const std::string& description) {
    this->description = description;
}