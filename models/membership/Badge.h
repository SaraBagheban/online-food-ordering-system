#ifndef BADGE_H
#define BADGE_H

#include <string>

class Badge {
private:
    std::string name;
    std::string description;

public:
    Badge();
    Badge(const std::string& name, const std::string& description);

    std::string getName() const;
    std::string getDescription() const;

    void setName(const std::string& name);
    void setDescription(const std::string& description);
};

#endif