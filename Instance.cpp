#include "Instance.h"

Instance::Instance(World * world, int hitPoints, int speed, int cost, int attackRange, int buildingTime, int posX, int posY)
{
    this->world = world;
    this->hitPoints = hitPoints;
    this->speed = speed;
    this->cost = cost;
    this->attackRange = attackRange;
    this->buildingTime = buildingTime;
    this->posX = posX;
    this->posY = posY;
}

std::string Instance::getName()
{
    return this->name;
}

int Instance::getHitPoints()
{
    return this->hitPoints;
}

void Instance::setHitPoints(int hitPointsValue)
{
    this->hitPoints = hitPointsValue;
}

int Instance::getBuildingCounter()
{
    return this->buildingCounter;
}

void Instance::setBuildingCounter(int counter)
{
    this->buildingCounter = counter;
}

bool Instance::getMovePossible()
{
    return this->movePossible;
}

void Instance::setMovePossible(bool status)
{
    this->movePossible = status;
}

void Instance::setPosX(int newPosX)
{
    this->posX = newPosX;
}

void Instance::setPosY(int newPosY)
{
    this->posY = newPosY;
}

int Instance::getPosX() const
{
    return this->posX;
}

int Instance::getPosY() const
{
    return this->posY;
}


char Instance::getBaseSymbol() const
{
    return this->baseSymbol;
}

void Instance::setBaseSymbol(char settingSymbol)
{
    this->baseSymbol = settingSymbol;
}

int Instance::getSpeed() const
{
    return this->speed;
}

char Instance::getSymbol()
{
    return this->symbol;
}

int Instance::getAttackRange()
{
    return this->attackRange;
}


Instance::~Instance()
= default;

