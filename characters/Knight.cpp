#include "Knight.h"

Knight::Knight(World* world, int pos_x, int pos_y)
        :Character(world, 70, 5, 400, 1, 5, pos_x, pos_y)
{
    this->buildingCounter = 5;
    this->symbol = 'K';
    this->movePossible = false;
}

Knight::Knight(World* world, int hitPoints, int pos_x, int pos_y, int buildingCounter)
        :Character(world, hitPoints, 5, 400, 1, 5, pos_x, pos_y)
{
    this->buildingCounter = buildingCounter;
    this->movePossible = true;

}

void Knight::action()
{
    //...
}

void Knight::move()
{
    //...
}

