#ifndef INTERVIEW_WORLD_H
#define INTERVIEW_WORLD_H
#include "utils/HeadersConnector.h"


using namespace std;

/*
 * The World class contains all the mechanics of operating the game.
 */

class World
{

protected:
    bool gameEnd;
    int round;
    int numberOrganisms;


    Instance ***map{};
    int mapSizeX, mapSizeY;
    int maxMapSize = mapSizeX * mapSizeY;

    int playersTurn;



public:
    World(int mapSizeX, int mapSizeY);

    ~World();

    int getRound();

    void createMap();

    bool getGameStatus();

    Instance *getField(int x, int y);

    void displayMap();

    void increaseRound();

    void createExistingCharacter(Instance* instance);

    void createCharacterInBase(Base *base);

    void removeInstanceFromGame(Instance *instance, int posX, int posY);

    void setBaseDuringCrafting(Base *base, Instance *character, bool status, int goldToSub);

    void makeRound();

    void setInstanceOnMap(Instance *instance, int pos_x, int pos_y);

    bool checkMapField(int posX, int posY);

    void handleBuilding(Building *building);
    void handleCharacter(Character *character);

    static char displayMenu();

    static void displayGameInfo();
};


#endif
