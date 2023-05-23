#include "Catapult.h"

Catapult::Catapult(World* world, int posX, int posY, char baseSymbol)
        :Character(world, 50, 2, 800, 7, 6, posX, posY)
{
    this->buildingCounter = buildingTime;
    this->movePossible = false;
    this->symbol = 'C';
    name = "Catapult";
    this->baseSymbol = baseSymbol;
    this->newUnitStatus = true;
}


Catapult::Catapult(World* world, int hitPoints, int posX, int posY, int buildingCounter, char baseSymbol)
        :Character(world, hitPoints, 2, 800, 7, 6, posX, posY)
{
    this->buildingCounter = buildingCounter;
    this->movePossible = true;
    this->symbol = 'C';
    name = "Catapult";
    this->baseSymbol = baseSymbol;
    this->newUnitStatus = false;

}


// initialize get attack Values func
int Catapult::getAttackValue(const std::string &unitName) const
{
    static std::unordered_map<std::string, int> unitValues = {
            {"Knight", 40},
            {"Swordsman", 40},
            {"Archer", 40},
            {"Pikeman", 40},
            {"Catapult", 40},
            {"Ram", 40},
            {"Worker", 40},
            {"Base", 50}
    };

    auto it = unitValues.find(unitName);

    if (it != unitValues.end()) {
        return it->second;
    }

    return -1;
}