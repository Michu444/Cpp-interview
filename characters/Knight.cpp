#include "Knight.h"

Knight::Knight(World* world, int posX, int posY)
        :Character(world, 70, 5, 400, 1, 5, posX, posY)
{
    this->buildingCounter = 5;
    this->symbol = 'K';
    this->movePossible = false;
}

Knight::Knight(World* world, int hitPoints, int posX, int posY, int buildingCounter)
        :Character(world, hitPoints, 5, 400, 1, 5, posX, posY)
{
    this->buildingCounter = buildingCounter;
    this->movePossible = true;
    this->symbol = 'K';

}

void Knight::action()
{
    //...
}

void Knight::move()
{
    //...
}

