#include "SwordsMan.h"

SwordsMan::SwordsMan(World* world, int posX, int posY)
        :Character(world, 60, 2, 250, 1, 3, posX, posY)
{
    this->buildingCounter = 5;
    this->movePossible = false;
    this->symbol = 'S';
    name = "SwordsMan";


}

SwordsMan::SwordsMan(World* world, int hitPoints, int posX, int posY, int buildingCounter)
        :Character(world, hitPoints, 2, 250, 1, 3, posX, posY)
{
    this->buildingCounter = buildingCounter;
    this->movePossible = true;
    this->symbol = 'S';
    name = "SwordsMan";
}

void SwordsMan::action()
{
    //...
}

void SwordsMan::move()
{
    //...
}

