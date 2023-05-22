#include "Pikeman.h"


Pikeman::Pikeman(World* world, int posX, int posY, char baseSymbol)
        :Character(world, 50, 2, 200, 2, 3, posX, posY)
{
    this->buildingCounter = buildingTime;
    this->movePossible = false;
    this->symbol = 'P';
    name = "Pikeman";
    this->baseSymbol = baseSymbol;
    this->newUnitStatus = true;
}

Pikeman::Pikeman(World* world, int hitPoints, int posX, int posY, int buildingCounter, char baseSymbol)
        :Character(world, hitPoints, 2, 200, 2, 3, posX, posY)
{
    this->buildingCounter = buildingCounter;
    this->movePossible = true;
    this->symbol = 'P';
    name = "Pikeman";
    this->baseSymbol = baseSymbol;
    this->newUnitStatus = false;

}


// initialize get attack Values func
int Pikeman::getAttackValue(const std::string &unitName) const
{
    static std::unordered_map<std::string, int> unitValues = {
            {"Knight", 35},
            {"Swordsman", 15},
            {"Archer", 15},
            {"Pikeman", 15},
            {"Catapult", 15},
            {"Ram", 10},
            {"Worker", 15},
            {"Base", 10}
    };

    auto it = unitValues.find(unitName);

    if (it != unitValues.end()) {
        return it->second;
    }

    return -1;
}