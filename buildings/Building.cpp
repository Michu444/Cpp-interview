#include "Building.h"


Building::Building(World* world, int hitPoints, int speed, int cost, int attack_range, int building_time, int posX, int posY)
:Instance(world, hitPoints, 0, 0, 0, 0, posX, posY)
{}

void Building::action()
{}

void Building::move()
{}

int Building::getPosX()
{
    return this->posX;
}

int Building::getPosY()
{
    return this->posY;
}
