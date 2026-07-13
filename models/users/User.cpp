#include "User.h"

User::User() : id(0), name(""), phone("") {
}

User::User(int id, const std::string& name, const std::string& phone)
    : id(id), name(name), phone(phone) {
}

User::~User() {
}

int User::getId() const {
    return id;
}

std::string User::getName() const {
    return name;
}

std::string User::getPhone() const {
    return phone;
}

void User::setId(int id) {
    this->id = id;
}

void User::setName(const std::string& name) {
    this->name = name;
}

void User::setPhone(const std::string& phone) {
    this->phone = phone;
}