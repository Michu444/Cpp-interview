#ifndef INTERVIEW_BASE_H
#define INTERVIEW_BASE_H
#include "Building.h"

class Base : public Building
{
protected:

    long int gold;

    Instance *characterInBase{};
    bool unitInProgress{};

    int numberOfUnits;

public:
    Base(World* world, int posX, int posY, char symbol);

    void action() override;

    long int getGold();

    void setGold(long int goldToSet);

    int getNumberOfUnits();

    void setNumberOfUnits(int numberOfUnits);

    Instance *getCharacterInBase();

    void setCharacterInBase(Instance *character);

    bool getStatusInProgress();

    void setStatusInProgress(bool status);

};

#endif