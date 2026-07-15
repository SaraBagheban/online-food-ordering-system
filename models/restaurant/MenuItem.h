#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>

class MenuItem {
private:
    int id;
    std::string name;
    std::string description;
    double basePrice;
    bool available;
    bool specialItem;

public:
    MenuItem();
    MenuItem(int id, const std::string& name,
             const std::string& description,
             double basePrice, bool available, 
             bool specialItem);

    virtual ~MenuItem();

    
    int getId() const;
    std::string getName() const;
    std::string getDescription() const;
    double getBasePrice() const;
    bool getAvailable() const;
    bool isSpecialItem() const;


    void setId(int id);
    void setName(const std::string& name);
    void setDescription(const std::string& description);
    void setBasePrice(double basePrice);
    void setAvailable(bool available);
    void setSpecialItem(bool specialItem);
    

    virtual double calculatePrice() const = 0;
    virtual void showDetails() const = 0;
};

#endif