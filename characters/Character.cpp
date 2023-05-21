#include "Character.h"

Character::Character(World* world, int hitPoints, int speed, int cost, int attack_range, int building_time, int posX, int posY)
:Instance(world, hitPoints, speed, cost, attack_range, building_time, posX, posY)
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
    return this->posX;
}

int Character::getPosY()
{
    return this->posY;
}
