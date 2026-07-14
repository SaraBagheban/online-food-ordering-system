#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <string>

class Restaurant {
private:
    int id;
    std::string name;
    std::string address;
    std::string phone;
    std::string description;
    int prepTime;
    bool isActive;

public:
    Restaurant();
    Restaurant(int id, const std::string& name,
               const std::string& address,
               const std::string& phone,
               const std::string& description,
               int prepTime, bool isActive);

    int getId() const;
    std::string getName() const;
    std::string getAddress() const;
    std::string getPhone() const;
    std::string getDescription() const;
    int getPrepTime() const;
    bool getIsActive() const;

    void setId(int id);
    void setName(const std::string& name);
    void setAddress(const std::string& address);
    void setPhone(const std::string& phone);
    void setDescription(const std::string& description);
    void setPrepTime(int prepTime);
    void setIsActive(bool isActive);
};

#endif