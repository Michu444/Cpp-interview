#include "Character.h"

Character::Character(World* world, int hitPoints, int speed, int cost, int attack_range, int building_time, int pos_x, int pos_y)
:Instance(world, hitPoints, speed, cost, attack_range, building_time, pos_x, pos_y)
{}

void Character::action()
{}

void Character::move()
{}

char Character::getSymbol()
{
    return this->symbol;
}

int Character::getPosX()
{
    return this->pos_x;
}

int Character::getPosY()
{
    return this->pos_y;
}


