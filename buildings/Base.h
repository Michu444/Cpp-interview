#ifndef INTERVIEW_BASE_H
#define INTERVIEW_BASE_H
#include "Building.h"

class Base : public Building
{
protected:
    char symbol;

    long int gold;
    World *world;

    Instance *characterInProgress{};
    bool unitInProgress{};

    int numberOfUnits;

public:
    Base(World* world, int posX, int posY, char symbol);

    void action() override;

    char getSymbol() override;

    long int getGold();

    void setGold(long int goldToSet);

    int getNumberOfUnits();

    void setNumberOfUnits(int numberOfUnits);

    Instance *getCharacterInProgress();

    void setCharacterInProgress(Instance *character);

    bool getStatusInProgress();

    void displayBaseInfo();

    void setStatusInProgress(bool status);

};

#endif