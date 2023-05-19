#include "GoldMine.h"

GoldMine::GoldMine(World* world, int posX, int posY)
        : Building(world, 0, 0, 0, 0, 0, posX, posY)
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