#include "SwordsMan.h"

SwordsMan::SwordsMan(World* world, int pos_x, int pos_y)
        :Character(world, 60, 2, 250, 1, 3, pos_x, pos_y)
{
    this->buildingCounter = 5;
    this->symbol = 'S';
    this->movePossible = false;
}

SwordsMan::SwordsMan(World* world, int hitPoints, int pos_x, int pos_y, int buildingCounter)
        :Character(world, hitPoints, 2, 250, 1, 3, pos_x, pos_y)
{
    this->buildingCounter = buildingCounter;
    this->movePossible = true;

}

void SwordsMan::action()
{
    //...
}

void SwordsMan::move()
{
    //...
}
