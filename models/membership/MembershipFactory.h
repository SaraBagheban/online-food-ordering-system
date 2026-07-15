#ifndef MEMBERSHIPFACTORY_H
#define MEMBERSHIPFACTORY_H

#include "MembershipLevel.h"
#include <string>

class MembershipFactory {
public:
    static MembershipLevel* createLevel(
        const std::string& levelName
    );
};

#endif