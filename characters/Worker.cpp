#include "Worker.h"

Worker::Worker(World* world, int posX, int posY)
        :Character(world, 20, 2, 100, 1, 2, posX, posY)
{
    this->buildingCounter = 2;
    this->movePossible = false;
    this->symbol = 'W';
    this->name = "Worker";
}

Worker::Worker(World* world, int hitPoints, int posX, int posY, int buildingCounter)
        :Character(world, hitPoints, 2, 100, 1, 2, posX, posY)
{
    this->buildingCounter = buildingCounter;
    this->movePossible = true;
    this->symbol = 'W';
    this->name = "Worker";
}

void Worker::action()
{
}