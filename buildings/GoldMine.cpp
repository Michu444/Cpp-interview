#include "GoldMine.h"

GoldMine::GoldMine(World* world, int posX, int posY)
        : Building(world, 0, 0, 0, 0, 0, posX, posY)
{
    this->occupied = false;
    this->symbol = '6';
    this->name = "Gold Mine";
}

char GoldMine::getSymbol()
{
    return this->symbol;
}