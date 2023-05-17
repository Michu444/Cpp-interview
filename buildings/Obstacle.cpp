#include "Obstacle.h"

Obstacle::Obstacle(World* world, int pos_x, int pos_y)
        : Building(world, 0, 0, 0, 0, 0, pos_x, pos_y)
{}

void Obstacle::action()
{}

void Obstacle::move()
{}