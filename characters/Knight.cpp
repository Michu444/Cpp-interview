#include "Knight.h"

Knight::Knight(World* world, int posX, int posY, char baseSymbol)
        :Character(world, 70, 5, 400, 1, 5, posX, posY)
{
    this->buildingCounter = buildingTime;
    this->movePossible = false;
    this->symbol = 'K';
    name = "Knight";
    this->baseSymbol = baseSymbol;
    this->newUnitStatus = true;
}


Knight::Knight(World* world, int hitPoints, int posX, int posY, int buildingCounter, char baseSymbol)
        :Character(world, hitPoints, 5, 400, 1, 5, posX, posY)
{
    this->buildingCounter = buildingCounter;
    this->movePossible = true;
    this->symbol = 'K';
    name = "Knight";
    this->baseSymbol = baseSymbol;
    this->newUnitStatus = false;

}


// initialize get attack Values func
int Knight::getAttackValue(const std::string &unitName) const
{
    static std::unordered_map<std::string, int> unitValues = {
            {"Knight", 35},
            {"Swordsman", 35},
            {"Archer", 35},
            {"Pikeman", 35},
            {"Catapult", 35},
            {"Ram", 50},
            {"Worker", 35},
            {"Base", 35}
    };

    auto it = unitValues.find(unitName);

    if (it != unitValues.end()) {
        return it->second;
    }

    return -1;
}