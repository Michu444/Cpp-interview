#include "World.h"



// adding units on world and place it on map
void World::addTestUnits()
{
// TESTING UNITS

    player_1 = new Base(this, 0, 0, '1');
    this->setInstanceOnMap(player_1, 0, 0);

    player_2 = new Base(this, 11, 11, '2');
    this->setInstanceOnMap(player_2, 11, 11);

//    auto *knight = new Knight(this, 5, 5, '1');
//    this->setInstanceOnMap(knight, knight->getPosX(), knight->getPosY());
//    knight->setMovePossible(true);
//    player_1->setNumberOfUnits(1);
//    numberOrganisms++;
//
//
//    auto *worker1 = new Worker(this, 5, 6, '2');
//    this->setInstanceOnMap(worker1, worker1->getPosX(), worker1->getPosY());
//    worker1->setMovePossible(true);
//    player_2->setNumberOfUnits(1);
//    numberOrganisms++;
//
//
//    auto *catapult = new Catapult(this, 4, 5, '1');
//    this->setInstanceOnMap(catapult, catapult->getPosX(), catapult->getPosY());
//    catapult->setMovePossible(true);
//    player_1->setNumberOfUnits(1);
//    numberOrganisms++;

}

/*
 * Basic constructor to create game world.
 *
 * @param mapSizeX: width map size
 * @param mapSizeY: height map size
 */
World::World(int mapSizeX, int mapSizeY)
{
    this->mapSizeX = mapSizeX;
    this->mapSizeY = mapSizeY;
    this->maxMapSize = mapSizeX * mapSizeY;

    round = 1;
    numberOrganisms = 0;
    gameEnd = false;

    this->createMap();

    this->addTestUnits();

    if (player_1 == nullptr || player_2 == nullptr)
    {
        throw std::logic_error("Program Crashed! You have to declare two players!");
    }

}

/*
 * Destructor where map object is also deleting.
 */
World::~World()
{
    for (int x = 0; x < this->mapSizeX; ++x)
    {
        for (int y = 0; y < this->mapSizeY; ++y)
        {
            delete map[x][y];
        }
        delete[] map[x];
    }
    delete[] map;
}


/*
 * Main method responsible for all processes during single round.
 */
void World::makeRound()
{
    system("clear");


    if (round >= 2000 || player_1->getHitPoints() <= 0 || player_2->getHitPoints() <= 0) // TODO maybe add var if gameEnd == true do this too..
    {
        this->endGame();
        gameEnd = true;
    }

    std::cout << "\nRound: " << this->getRound() << "\n\n";


    for (int y = 0; y < this->mapSizeX; ++y)
    {
        for (int x = 0; x < this->mapSizeY; ++x)
        {

            if (auto *base = dynamic_cast<Base*>(map[x][y]))
            {
                this->handleBuilding(base);

            }
            else if (auto *character = dynamic_cast<Character*>(map[x][y]))
            {
                if (character->getMovePossible())
                {
                    this->handleCharacter(character);
                    character->setMovePossible(false);
                }
                else
                {
//                    std::cout << "Unit: " << character->getName() << " at position: (" << character->getPosX()
//                              << ", " << character->getPosY() << ") cant move!\n";
                }
                continue;
            }
            else if (map[x][y] == nullptr)
            {
                continue;
            }
            else
            {
                continue;
            }
        }
    }

    this->makeAllCharactersMovePossibility();
    this->displayMap();
    std::cout << "\nEND OF THE " << this->getRound() << " ROUND! PRESS ENTER TO GO TO NEXT ROUND!";
    getchar();
    while (getchar() != '\n') {}
    this->increaseRound();
}

/*
 * Searches for instances around that can be attacked by instance which is turn.
 *
 * @param instance: An instance that can attack other instance.
 */
std::vector<Instance*> World::displayInstancesAround(Instance *instance)
{
    int areaDiameter = instance->getAttackRange();
    int instancePosX = instance->getPosX();
    int instancePosY = instance->getPosY();

    std::vector<Instance*> unitsAround;

    for (int x = instancePosX - areaDiameter; x <= instancePosX + areaDiameter; ++x)
    {
        for (int y = instancePosY - areaDiameter; y <= instancePosY + areaDiameter; ++y)
        {
            if (x >= 0 && x < mapSizeX && y >= 0 && y < mapSizeY && map[x][y] != nullptr)
            {
                if (map[x][y]->getBaseSymbol() != instance->getBaseSymbol())
                {
                    if (auto *character = dynamic_cast<Character*>(map[x][y]))
                    {
                        unitsAround.push_back(map[x][y]);
                    }
                    else if(auto *base = dynamic_cast<Base*>(map[x][y]))
                    {
                        unitsAround.push_back(map[x][y]);
                    }
                }
                else
                {
                    continue;
                }

            }
        }
    }
    return unitsAround;
}


/*
 * Method responsible for attacking one unit against another.
 *
 * @param attacker: Instance that attacks
 * @param defender: Instance that is under attack
 */
void World::attackUnit(Instance *attacker, Instance* defender)
{
    this->displayMap();

    int lifePointsTaken = attacker->getAttackValue(defender->getName());

    std::cout << attacker->getName() << " (" << attacker->getPosX() << ", " << attacker->getPosY() << ") attacked "
              << defender->getName() << " (" << defender->getPosX() << ", " << defender->getPosY() << ") and gave "
               << lifePointsTaken << " dmg !!\n\n";

    defender->setHitPoints(defender->getHitPoints() - lifePointsTaken);

    if (defender->getHitPoints() <= 0)
    {
        if (auto *base = dynamic_cast<Base*>(defender))
        {
            std::cout << "YOU DESTROYED ENEMY BASE!" << "\n";
            std::this_thread::sleep_for(std::chrono::seconds(3)); // using thread lib for availability in windows and linux
            this->gameEnd = true;
            this->endGame();
        }

        this->removeInstanceFromGame(defender);
        std::cout << "This attack killed " << defender->getName() << "!\n";
    }
    std::this_thread::sleep_for(std::chrono::seconds(3)); // using thread lib for availability in windows and linux
}


void World::displayUnitStats(Instance *instance)
{
    std::cout << "Unit: " << instance->getName() << " (" << instance->getPosX() << ", " << instance->getPosY() << "\n";
    std::cout << "Hit points: " << instance->getHitPoints() << "\n";

}

/*
 * Handle character instances in single round.
 *
 * @param character: Character object to handle.
 */
void World::handleCharacter(Character *character)
{
    int numberMoves = character->getSpeed();

    while(numberMoves)
    {
        this->displayMap();
        std::cout << "\n---------------------\n";
        int choose;
        std::cout << "If you choose a move or an action and take no action, you lose one move point (Move) or all move points (Action)!\n\n";
        this->displayInstanceInfo(character);
        std::cout << "Move points: " << numberMoves << "\n\n";
        std::cout << "[1] Move character" << "\n";
        std::cout << "[2] Make action!" << "\n";
        std::cout << "[Q] Skip the turn" << "\n";
        std::cout << "What do you want to do? ";
        choose = getchar();
        if (isalpha(choose))
        {
            choose = toupper(choose);
        }
        while (getchar() != '\n') {}
        std::cout << "\n\n";


        switch(choose)
        {
            case '1':
            {
                character->move();
                numberMoves--;
                break;
            }
            case '2':
            {
                character->action();
                numberMoves = 0;
                break;
            }
            case 'Q':
            {
                return;
            }
            default:
            {
                std::cout << "Wrong option! Try again." << "\n";
                break;
            }
        }
    }
}


/*
 * Handle building instances in single round.
 *
 * @param building: Object to handle.
 */
void World::handleBuilding(Building *building)
{
    if (Base *base = dynamic_cast<Base*>(building))
    {
        if (base->getStatusInProgress()) // check if base creating character
        {
            if (base->getBuildingCounter() > 0)
            {
                base->setBuildingCounter(base->getBuildingCounter() - 1);
            }
            else if (base->getBuildingCounter() == 0)
            {
                this->numberOrganisms++;
                base->setNumberOfUnits(base->getNumberOfUnits() + 1);
                base->setStatusInProgress(false);
                base->getCharacterInBase()->setMovePossible(true); // after creating, character can move
                // TODO ADD UNIT ON MAP - THINK ABOUT HOW TO ADD IT ON BASE FIELD
            }
        }
    }

    building->action();
}


/*
 * Place instance read from file. Checking if it is possible to place on the map. If unit exist on map field, unit
 * will not be placed.
 *
 * @param instance: Object which we need to place on map.
 */
void World::placeSavedExistingCharacter(Instance* instance)
{
    if (numberOrganisms < maxMapSize && this->checkMapField(instance, instance->getPosX(), instance->getPosY()))
    {
        this->map[instance->getPosX()][instance->getPosY()] = instance;
    }
}


/*
 * Creating new character in base object. Whether object will be created depends on the amount of the gold in player base.\
 * Checking also whether amount of object in map is not bigger than map size.
 *
 * @param base: player Base object
 */
void World::createCharacterInBase(Base *base)
{
    int unitChosen = true;


    if (numberOrganisms < maxMapSize && !base->getStatusInProgress())
    {
        while(unitChosen)
        {
            int choose;

            this->displayMap();
            this->displayInstanceInfo(base);

            std::cout << "[1] Knight     (5 rounds) (400 gold)" << "\n";
            std::cout << "[2] Swordsman  (3 rounds) (250 gold)" << "\n";
            std::cout << "[3] Archer     (3 rounds) (250 gold)" << "\n";
            std::cout << "[4] Pikeman    (3 rounds) (200 gold)" << "\n";
            std::cout << "[5] Ram        (4 rounds) (500 gold)" << "\n";
            std::cout << "[6] Catapult   (6 rounds) (800 gold)" << "\n";
            std::cout << "[7] Worker     (2 rounds) (100 gold)" << "\n";
            std::cout << "[Q] Skip the turn" << "\n\n";
            std::cout << "Which character do you want to create? ";
            choose = getchar();
            if (isalpha(choose))
            {
                choose = toupper(choose);
            }
            while (getchar() != '\n') {}
            std::cout << "\n";

            switch(choose)
            {
                case '1':
                {
                    if (base->getGold() >= 400)
                    {
                        Knight *knight = new Knight(this, base->getPosX(), base->getPosY(), base->getSymbol());
                        this->setBaseDuringCrafting(base, knight, true, 400);
                        unitChosen = false;
                        break;
                    }
                    else
                    {
                        std::cout << "\nYou dont have enough gold!" << "\n\n";
                        break;
                    }

                }
                case '2':
                {
                    if (base->getGold() >= 250)
                    {
                        Swordsman *swordsman = new Swordsman(this, base->getPosX(), base->getPosY(), base->getSymbol());
                        this->setBaseDuringCrafting(base, swordsman, true, 250);
                        unitChosen = false;
                        break;
                    }
                    else
                    {
                        std::cout << "\nYou dont have enough gold!" << "\n\n";
                        break;
                    }
                }
                case '3':
                {
                    if (base->getGold() >= 250)
                    {
                        Archer *archer = new Archer(this, base->getPosX(), base->getPosY(), base->getSymbol());
                        this->setBaseDuringCrafting(base, archer, true, 250);
                        unitChosen = false;
                        break;
                    }
                    else
                    {
                        std::cout << "\nYou dont have enough gold!" << "\n\n";
                        break;
                    }
                }
                case '4':
                {
                    if (base->getGold() >= 200)
                    {
                        Pikeman *pikeman = new Pikeman(this, base->getPosX(), base->getPosY(), base->getSymbol());
                        this->setBaseDuringCrafting(base, pikeman, true, 200);
                        unitChosen = false;
                        break;
                    }
                    else
                    {
                        std::cout << "\nYou dont have enough gold!" << "\n\n";
                        break;
                    }
                }
                case '5':
                {
                    if (base->getGold() >= 250)
                    {
                        Ram *ram = new Ram(this, base->getPosX(), base->getPosY(), base->getSymbol());
                        this->setBaseDuringCrafting(base, ram, true, 250);
                        unitChosen = false;
                        break;
                    }
                    else
                    {
                        std::cout << "\nYou dont have enough gold!" << "\n\n";
                        break;
                    }
                }
                case '6':
                {
                    if (base->getGold() >= 800)
                    {
                        Catapult *catapult = new Catapult(this, base->getPosX(), base->getPosY(), base->getSymbol());
                        this->setBaseDuringCrafting(base, catapult, true, 800);
                        unitChosen = false;
                        break;
                    }
                    else
                    {
                        std::cout << "\nYou dont have enough gold!" << "\n\n";
                        break;
                    }
                }
                case '7':
                {
                    if (base->getGold() >= 250)
                    {
                        Worker *worker = new Worker(this, base->getPosX(), base->getPosY(), base->getSymbol());
                        this->setBaseDuringCrafting(base, worker, true, 250);
                        unitChosen = false;
                        break;
                    }
                    else
                    {
                        std::cout << "\nYou dont have enough gold!" << "\n\n";
                        break;
                    }
                }
                case 'Q':
                {
                    return;
                }
                default:
                {
                    std::cout << "Wrong option! Try again." << "\n";
                    break;
                }
            }

            if (!unitChosen)
            {
                this->displayMap();
                std::cout << "\n--------------\n";
                std::cout << "Base: " << base->getSymbol() << "\n";
                std::cout << "Started creating: " << base->getCharacterInBase()->getName() << "\n";
                std::cout << "Rounds to create: " << base->getCharacterInBase()->getBuildingCounter() << "\n";
                std::this_thread::sleep_for(std::chrono::seconds(3)); // using thread lib for availability in windows and linux
            }
        }
    }
    else if (numberOrganisms < maxMapSize && base->getStatusInProgress())
    {
        base->getCharacterInBase()->setBuildingCounter(base->getCharacterInBase()->getBuildingCounter() - 1);
        std::cout << "Rounds to end " << base->getCharacterInBase()->getName() << " creating: "
                  << base->getCharacterInBase()->getBuildingCounter();
    }
    else
    {
        std::cout << "Map is full, you cant create new Object in base!" << "\n";
    }
}


/*
 * Removes Instance object from map, clear memory and decrement number of available in game instances. Method
 * using, for example, when character will be defeated by other unit.
 *
 * @param instance: Instance object to remove.
 *
 * @param posX: x coord of the object to remove.
 * @param posY: y coord of the object to remove.
 */
void World::removeInstanceFromGame(Instance *instance)
{
    this->map[instance->getPosX()][instance->getPosY()] = nullptr;
    delete instance;
    this->numberOrganisms--;

    // decrement number of units for specific base
    if (instance->getBaseSymbol() == '1')
    {
        player_1->setNumberOfUnits(player_1->getNumberOfUnits() - 1);
    }
    else if (instance->getBaseSymbol() == '2')
    {
        player_2->setNumberOfUnits(player_2->getNumberOfUnits() - 1);
    }
    else
    {
        std::cout << "Could not recognize base player!" << "\n";
    }
}


/*
 * Set base status when user picked character to create.
 *
 * @param base: Player base object.
 * @param character: Character object chosen to craft.
 * @param status: Crafting status in base.
 * @param goldToSub: Number of gold to subtract from base gold.
 */
void World::setBaseDuringCrafting(Base* base, Instance *character, bool status, long int goldToSub)
{
    base->setCharacterInBase(character);
    base->setStatusInProgress(status);
    base->setGold(base->getGold() - goldToSub);
    base->setBuildingCounter(character->getBuildingCounter());

}


/*
 * Setting object on map in given coords place. If object was existing on map, set nullptr on old field.
 *
 * @param instance: Object to be placed on map.
 * @param posX: x coord where object will be placed on map.
 * @param posY: y coord where object will be placed on map.
 */
void World::setInstanceOnMap(Instance *instance, int posX, int posY)
{
    if (posX < this->mapSizeX && posY < this->mapSizeY)
    {
        // if new unit is moving from base
        if (auto* base = dynamic_cast<Base*>(map[instance->getPosX()][instance->getPosY()]))
        {
            instance->setPosX(posX);
            instance->setPosY(posY);
        }
        else if (map[instance->getPosX()][instance->getPosY()] == instance)
        {
            map[instance->getPosX()][instance->getPosY()] = nullptr;
            instance->setPosX(posX);
            instance->setPosY(posY);
        }

        this->map[posX][posY] = instance;
    }
}


/*
 * Get object located on given coords in map.
 *
 * @param x: x coord to check on map.
 * @param y: y coord to check on map.
 *
 * @return: Instance object - map position.
 */
Instance *World::getField(int x, int y)
{
    return this->map[x][y];
}


/*
 * Checking if given place on map are empty or not.
 *
 * @param posX: x coord of checking place.
 * @param posY: y coord of checking place.
 *
 * @return: boolean status.
 */
bool World::checkMapField(Instance *instance, int posX, int posY)
{
    if ( posX < this->mapSizeX && posY < this->mapSizeY)
    {
        if (auto *worker = dynamic_cast<Worker*>(instance))
        {
            if (auto *goldmine = dynamic_cast<GoldMine*>(map[posX][posY]))
            {
                return true;
            }
        }

        if (this->map[posX][posY] == nullptr)
        {
            return true;
        }
    }
    return false;
}

void World::makeAllCharactersMovePossibility()
{
    for (int y = 0; y < this->mapSizeX; ++y)
    {
        for (int x = 0; x < this->mapSizeY; ++x)
        {
            if (Character *character = dynamic_cast<Character*>(map[x][y]))
            {
                character->setMovePossible(true);
            }
        }
    }
}


int World::getRound()
{
    return this->round;
}


bool World::getGameStatus()
{
    return this->gameEnd;
}


void World::increaseRound()
{
    this->round++;
}

int World::getMapSizeX()
{
    return this->mapSizeX;
}

int World::getMapSizeY()
{
    return this->mapSizeY;
}

/*
 * Summarize game and make operations during ending game.
 */
void World::endGame()
{
    Base *winner;

    if (this->getRound() >= 2000 && player_1->getHitPoints() > 0 && player_2->getHitPoints() > 0)
    {
        if (player_1->getNumberOfUnits() > player_2->getNumberOfUnits())
        {
            winner = player_1;
        }
        else
        {
            winner = player_2;
        }
    }
    else if (player_1->getHitPoints() > player_2->getHitPoints())
    {
        winner = player_1;
    }
    else if (player_1->getHitPoints() < player_2->getHitPoints())
    {
        winner = player_2;
    }
    else
    {
        std::cout << "----- GAME END! -----" << "\n";
        std::cout << "-----  WINNER   -----" << "\n";
        std::cout << "-----   DRAW!   ---- " << "\n";
        std::cout << "  CONGRATULATIONS!!! " << "\n";
        getchar();
        exit(0);
    }

    system("clear"); // TODO CHANGE IT

    std::cout << "----- GAME END! -----" << "\n";
    std::cout << "-----  WINNER   -----" << "\n";
    std::cout << "----- PLAYER " << winner->getSymbol() << "!! ----" << "\n";
    std::cout << "  CONGRATULATIONS!!! " << "\n";
    getchar();
    exit(0);
}


/*
 * Creating empty map at the beginning of the game.
 */
void World::createMap() // remember to delete all map objects
{

    this->map = new Instance **[this->mapSizeX];

    for (int x = 0; x < this->mapSizeX; x++)
    {
        this->map[x] = new Instance * [this->mapSizeY];
    }

    for (int x = 0; x < mapSizeX; x++)
    {
        for (int y = 0; y < mapSizeY; y++)
        {
            map[x][y] = nullptr;
        }
    }
}

/*
 * Displaying info about Instance that is moving and lists possible options to choose from.
 *
 * @param instance: Instance that is moving
 */
void World::displayInstanceInfo(Instance *instance)
{
    if(Base *base = dynamic_cast<Base*>(instance))
    {
        std::cout << "\n---------------------\n";
        std::cout << "Base turn" << " at position: (" << base->getPosX() << ", " << base->getPosY() << ")\n";
        std::cout << "Hit points: " << base->getHitPoints() << "\n";
        std::cout << "Gold: " << base->getGold() << "\n";
        std::cout << "Number of Units: " << base->getNumberOfUnits() << "\n";

        if (base->getStatusInProgress())
        {
            std::cout << "Unit in progress: " << base->getCharacterInBase()->getName() << " (rounds left: "
                      << base->getBuildingCounter() << ") \n";
        }

        std::cout << "\n";

    }
    else if (Character *character = dynamic_cast<Character*>(instance))
    {
        std::cout << "\n---------------------\n";
        std::cout << "Character turn: " << character->getName() << " at position: (" << character->getPosX() << ", " << character->getPosY() << ")\n";
        std::cout << "\n---------------------\n";

        std::cout << "Hit points: " << character->getHitPoints() << "\n";
        std::cout << "Attack range: " << character->getAttackRange() << "\n";
    }
    else
    {
        // TODO IDK WHAT TO DO
    }
}

/*
 * Displays a representation of the map object. Each cell contains object or empty field.
 */
void World::displayMap()
{
    system("clear");

    // display first index row
    for (int i = 0; i < mapSizeX; i++)
    {
        if (i == 0)
        {
            std::cout << "     " << i;
        }
        else if (i < 10)
        {
            std::cout << "    " << i;
        }
        else
        {
            std::cout << "   " << i;
        }
    }

    std::cout << "\n";

    // display rows
    for (int y = 0; y < mapSizeY; y++)
    {
        if (y < 10)
        {
            std::cout << y << "  ";
        }
        else
        {
            std::cout << y << " ";
        }

        for (int x = 0; x < mapSizeX; x++)
        {
            if (getField(x, y) == nullptr)
            {
                std::cout << "  0  ";
            }
            else
            {
                std::cout << "  " << getField(x,y)->getSymbol() << "  ";
            }
        }

        std::cout << "\n";
    }
    std::cout << "\n----\n";
    std::cout << "Round: " << this->getRound();
    std::cout << "\n----\n";
}


/*
 * Displays menu in console.
 */
char World::displayMenu()
{
    char choose;

    do
    {
//        system("clear"); // TODO CHANGE TO WORK ON LINUX
         system("clear");

        std::cout << "----- MAIN MENU -----" << "\n";
        std::cout << " N - Create new game " << "\n";
        std::cout << " L - Load game       " << "\n";
        std::cout << " I - Game info       " << "\n";
        std::cout << " Q - Quit game       " << "\n";

        std::cout << "\nChoose option: ";

        choose = getchar();
        if (isalpha(choose))
        {
            choose = toupper(choose);
        }
        while (getchar() != '\n') {}

        if (choose != 'N' && choose != 'L' && choose != 'Q' && choose != 'I')
        {
            system("clear");
            std::cout << "\nInvalid option. Please try again.";
            std::this_thread::sleep_for(std::chrono::seconds(1)); // using thread lib for availability in windows and linux
        }

    } while (choose != 'N' && choose != 'L' && choose != 'Q' && choose != 'I');

    return choose;
}


/*
 * Displays info in stdout about game and the title and author.
 */
void World::displayGameInfo()
{
    system("clear");

    std::cout << "------ WAR GAME! ------" << "\n";
    std::cout << "-----------------------" << "\n\n";
    std::cout << "----- DESCRIPTION -----" << "\n";
    std::cout << "-- INSTANCES WAR GAME -" << "\n";
    std::cout << "\n\n";
    std::cout << "------- AUTHOR --------" << "\n";
    std::cout << "    MICHAL DUDZIAK     " << "\n\n\n";

    std::cout << "Press enter to exit info: ";
    getchar();
    while (getchar() != '\n') {}
}