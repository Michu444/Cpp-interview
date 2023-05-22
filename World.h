#ifndef INTERVIEW_WORLD_H
#define INTERVIEW_WORLD_H
#include "utils/HeadersConnector.h"


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
    int maxMapSize;

    Base *player_1, *player_2;

    void addTestUnits();
public:
    World(int mapSizeX, int mapSizeY);

    ~World();

    int getRound();

    void createMap();

    bool getGameStatus();

    Instance *getField(int x, int y);

    void displayMap();

    void increaseRound();

    void placeSavedExistingCharacter(Instance* instance);

    void createCharacterInBase(Base *base);

    void removeInstanceFromGame(Instance *instance);

    void setBaseDuringCrafting(Base *base, Instance *character, bool status, long int goldToSub);

    void makeRound();

    std::vector<Instance*> displayInstancesAround(Instance *instance);

    void attackUnit(Instance *attacker, Instance* defender);

    void displayUnitStats(Instance *instance);

    void setInstanceOnMap(Instance *instance, int posX, int posY);

    bool checkMapField(Instance *instance, int posX, int posY);

    void makeAllCharactersMovePossibility();

    void handleBuilding(Building *building);
    void handleCharacter(Character *character);

    void endGame();

    void displayInstanceInfo(Instance *instance);

    static char displayMenu();

    static void displayGameInfo();

    int getMapSizeX();
    int getMapSizeY();
};


#endif
