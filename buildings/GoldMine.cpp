#include "GoldMine.h"

GoldMine::GoldMine(World* world, int pos_x, int pos_y)
        : Building(world, 0, 0, 0, 0, 0, pos_x, pos_y)
{
    occupied = false;
}

void GoldMine::action()
{
    // Implementacja akcji dla klasy
}

void GoldMine::move()
{
    // Implementacja ruchu dla klasy
}