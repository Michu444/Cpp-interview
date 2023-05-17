#include "Base.h"

Base::Base(World* world, int hitPoints, int speed, int cost, int attack_range, int building_time, int pos_x, int pos_y)
        : Building(world, hitPoints, speed, cost, attack_range, building_time, pos_x, pos_y)
{

}

void Base::action()
{
    // Implementacja akcji dla klasy Base
}

void Base::move()
{
    // Implementacja ruchu dla klasy Base
}