#include "Building.h"


Building::Building(World* world, int hitPoints, int speed, int cost, int attackRange, int buildingTime, int posX, int posY)
:Instance(world, hitPoints, 0, 0, 0, 0, posX, posY)
{
    movePossible = false;
}

int Building::getAttackValue(const std::string &unitName) const
{
    return 0;
}

void Building::action()
{}

void Building::move()
{}
