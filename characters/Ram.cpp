#include "Ram.h"

Ram::Ram(World* world, int posX, int posY, char baseSymbol)
        :Character(world, 90, 2, 500, 1, 4, posX, posY)
{
    this->buildingCounter = buildingTime;
    this->movePossible = false;
    this->symbol = 'R';
    name = "Ram";
    this->baseSymbol = baseSymbol;
    this->newUnitStatus = true;
}


Ram::Ram(World* world, int hitPoints, int posX, int posY, int buildingCounter, char baseSymbol)
        :Character(world, hitPoints, 2, 500, 1, 4, posX, posY)
{
    this->buildingCounter = buildingCounter;
    this->movePossible = true;
    this->symbol = 'R';
    name = "Ram";
    this->baseSymbol = baseSymbol;
    this->newUnitStatus = false;

}


// initialize get attack Values func
int Ram::getAttackValue(const std::string &unitName) const
{
    static std::unordered_map<std::string, int> unitValues = {
            {"Knight", 10},
            {"Swordsman", 10},
            {"Archer", 10},
            {"Pikeman", 10},
            {"Catapult", 10},
            {"Ram", 10},
            {"Worker", 10},
            {"Base", 50}
    };

    auto it = unitValues.find(unitName);

    if (it != unitValues.end()) {
        return it->second;
    }

    return -1;
}