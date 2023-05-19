#include "Instance.h"

Instance::Instance(World * world, int hitPoints, int speed, int cost, int attack_range, int building_time, int pos_x, int pos_y)
{
    this->world = world;
    this->hitPoints = hitPoints;
    this->speed = speed;
    this->cost = cost;
    this->attack_range = attack_range;
    this->building_time = building_time;
    this->pos_x = pos_x;
    this->pos_y = pos_y;
}

Instance::~Instance()
= default;

