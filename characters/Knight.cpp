#include "Knight.h"

Knight::Knight(World* world, int posX, int posY, char baseSymbol)
        :Character(world, 70, 5, 400, 1, 5, posX, posY)
{
    this->buildingCounter = 5;
    this->movePossible = false;
    this->symbol = 'K';
    name = "Knight";
    this->baseSymbol = baseSymbol;
    this->newUnitStatus = true;
}

Knight::Knight(World* world, int hitPoints, int posX, int posY, int buildingCounter, char baseSymbol)
        :Character(world, hitPoints, 5, 400, 1, 5, posX, posY)
{
    this->buildingCounter = buildingCounter;
    this->movePossible = true;
    this->symbol = 'K';
    name = "Knight";
    this->baseSymbol = baseSymbol;
    this->newUnitStatus = false;

}

void Knight::action()
{
}
