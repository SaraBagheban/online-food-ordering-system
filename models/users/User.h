#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    int id;
    std::string name;
    std::string phone;

public:
    User();
    User(int id, const std::string& name, const std::string& phone);
    virtual ~User();

    int getId() const;
    std::string getName() const;
    std::string getPhone() const;

    void setId(int id);
    void setName(const std::string& name);
    void setPhone(const std::string& phone);

    virtual void showMenu() = 0;
};

#endif