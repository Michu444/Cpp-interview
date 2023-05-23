#include "Swordsman.h"

Swordsman::Swordsman(World* world, int posX, int posY, char baseSymbol)
        :Character(world, 60, 2, 250, 1, 3, posX, posY)
{
    this->buildingCounter = buildingTime;
    this->movePossible = false;
    this->symbol = 'S';
    name = "Swordsman";
    this->baseSymbol = baseSymbol;
    this->newUnitStatus = true;
}


Swordsman::Swordsman(World* world, int hitPoints, int posX, int posY, int buildingCounter, char baseSymbol)
        :Character(world, hitPoints, 2, 250, 1, 3, posX, posY)
{
    this->buildingCounter = buildingCounter;
    this->movePossible = true;
    this->symbol = 'S';
    name = "Swordsman";
    this->baseSymbol = baseSymbol;
    this->newUnitStatus = false;
}


// initialize get attack Values func
int Swordsman::getAttackValue(const std::string &unitName) const
{
    static std::unordered_map<std::string, int> unitValues = {
            {"Knight", 30},
            {"Swordsman", 30},
            {"Archer", 30},
            {"Pikeman", 20},
            {"Catapult", 20},
            {"Ram", 30},
            {"Worker", 30},
            {"Base", 30}
    };

    auto it = unitValues.find(unitName);

    if (it != unitValues.end()) {
        return it->second;
    }

    return -1;
}