#include "MembershipFactory.h"

#include "MembershipLevel.h"
#include "NormalLevel.h"
#include "SilverLevel.h"
#include "GoldLevel.h"
#include "VIPLevel.h"

MembershipLevel* MembershipFactory::createLevel(
    const std::string& levelName) {

    if (levelName == "Normal") {
        return new NormalLevel();
    }

    if (levelName == "Silver") {
        return new SilverLevel();
    }

    if (levelName == "Gold") {
        return new GoldLevel();
    }

    if (levelName == "VIP") {
        return new VIPLevel();
    }

    return new NormalLevel();
}