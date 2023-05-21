#include "Building.h"


Building::Building(World* world, int hitPoints, int speed, int cost, int attackRange, int buildingTime, int posX, int posY)
:Instance(world, hitPoints, 0, 0, 0, 0, posX, posY)
{
    movePossible = false;
}

void Building::action()
{}

void Building::move()
{}
