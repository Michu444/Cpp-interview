#include "Archer.h"


Archer::Archer(World* world, int posX, int posY, char baseSymbol)
        :Character(world, 40, 2, 250, 5, 3, posX, posY)
{
    this->buildingCounter = buildingTime;
    this->movePossible = false;
    this->symbol = 'A';
    name = "Archer";
    this->baseSymbol = baseSymbol;
    this->newUnitStatus = true;
}

Archer::Archer(World* world, int hitPoints, int posX, int posY, int buildingCounter, char baseSymbol)
        :Character(world, hitPoints, 2, 250, 5, 3, posX, posY)
{
    this->buildingCounter = buildingCounter;
    this->movePossible = true;
    this->symbol = 'A';
    name = "Archer";
    this->baseSymbol = baseSymbol;
    this->newUnitStatus = false;

}

// initialize get attack Values func
int Archer::getAttackValue(const std::string &unitName) const
{
    static std::unordered_map<std::string, int> unitValues = {
            {"Knight", 15},
            {"Swordsman", 15},
            {"Archer", 15},
            {"Pikeman", 15},
            {"Catapult", 10},
            {"Ram", 10},
            {"Worker", 15},
            {"Base", 15}
    };

    auto it = unitValues.find(unitName);

    if (it != unitValues.end()) {
        return it->second;
    }

    return -1;
}
