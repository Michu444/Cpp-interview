#include "Building.h"


Building::Building(World* world, int hitPoints, int speed, int cost, int attack_range, int building_time, int pos_x, int pos_y)
:Instance(world, hitPoints, 0, 0, 0, building_time, pos_x, pos_y)
{}

void Building::action()
{
    //...
}

void Building::move()
{}


