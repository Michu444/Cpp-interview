#include "Obstacle.h"

Obstacle::Obstacle(World* world, int posX, int posY)
        : Building(world, 0, 0, 0, 0, 0, posX, posY)
{}

void Obstacle::action()
{}

void Obstacle::move()
{}