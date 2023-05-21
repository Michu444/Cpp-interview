#ifndef INTERVIEW_WORKER_H
#define INTERVIEW_WORKER_H
#include "Character.h"

class Worker :public Character
{
public:

    Worker(World* world, int posX, int posY); // creating factory new object

    Worker(World* world, int hitPoints, int posX, int posY, int buildingCounter); // creating Knight probably read from file

    void action() override;

};


#endif
