#include "Worker.h"

Worker::Worker(World* world, int posX, int posY, char baseSymbol)
        :Character(world, 20, 2, 100, 1, 2, posX, posY)
{
    this->buildingCounter = buildingTime;
    this->movePossible = false;
    this->symbol = 'W';
    name = "Worker";
    this->baseSymbol = baseSymbol;
    this->newUnitStatus = true;
}

Worker::Worker(World* world, int hitPoints, int posX, int posY, int buildingCounter, char baseSymbol)
        :Character(world, hitPoints, 2, 100, 1, 2, posX, posY)
{
    this->buildingCounter = buildingCounter;
    this->movePossible = true;
    this->symbol = 'W';
    name = "Worker";
    this->baseSymbol = baseSymbol;
    this->newUnitStatus = false;
}


// initialize get attack Values func
int Worker::getAttackValue(const std::string &unitName) const
{
    static std::unordered_map<std::string, int> unitValues = {
            {"Knight", 5},
            {"Swordsman", 5},
            {"Archer", 5},
            {"Pikeman", 5},
            {"Catapult", 5},
            {"Ram", 5},
            {"Worker", 5},
            {"Base", 1}
    };

    auto it = unitValues.find(unitName);

    if (it != unitValues.end()) {
        return it->second;
    }

    return -1;
}