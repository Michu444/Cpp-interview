#ifndef INTERVIEW_WORLD_H
#define INTERVIEW_WORLD_H
#include "utils/HeadersConnector.h"


using namespace std;


class World
{

protected:
    bool gameEnd;
    int round;
    int numberOrganisms;


    Instance ***map{};
    int map_size_x, map_size_y;

    int playersTurn;



public:
    World(int map_size_x, int map_size_y);

    ~World();

    int getRound();

    void createMap();

    bool getGameStatus();

    Instance *getField(int x, int y);

    void displayMap();

    void increaseRound();

    void createCharacter();

    void removeCharacter();

    void makeRound();

    void setInstance(Instance *instance, int pos_x, int pos_y);

    void handleBuilding(Building *building);
    void handleCharacter(Character *character);

    static char displayMenu();

    static void displayGameInfo();
};


#endif
