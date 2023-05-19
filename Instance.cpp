#include "Instance.h"

Instance::Instance(World * world, int hitPoints, int speed, int cost, int attack_range, int building_time, int posX, int posY)
{
    this->world = world;
    this->hitPoints = hitPoints;
    this->speed = speed;
    this->cost = cost;
    this->attack_range = attack_range;
    this->building_time = building_time;
    this->posX = posX;
    this->posY = posY;
}

std::string Instance::getName()
{
    return this->name;
}

int Instance::getHitPoints()
{
    return this->hitPoints;
}

Instance::~Instance()
= default;

