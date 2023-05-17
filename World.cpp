#include <iostream>
#include <conio.h>
#include <windows.h>
#include "World.h"


/*
 * Constructors & Destructors
 */

World::World(int map_size_x, int map_size_y)
{
    this->map_size_x = map_size_x;
    this->map_size_y = map_size_y;

    round = 0;
    numberOrganisms = 0;
    gameEnd = false;

    playersTurn = 1;

}

World::~World()
{
    for (int x = 0; x < this->map_size_x; ++x)
    {
        for (int y = 0; y < this->map_size_y; ++y)
        {
            delete map[x][y];
        }
        delete[] map[x];
    }
    delete[] map;
}



void World::createCharacter()
{
    if (numberOrganisms < map_size_x * map_size_y)
    {
        cout << std::endl;
    }

}

void World::makeRound()
{
    system("cls");

    if (round == 2000)
    {
        cout << "END GAME!\n";
        // this->endGame();
        gameEnd = true;
        return;
    }

    this->increaseRound();
    cout << "Round: " << this->getRound() << "\n\n";


    for (int y = 0; y < this->map_size_x; ++y)
    {
        for (int x = 0; x < this->map_size_y; ++x)
        {
            if (auto *building = dynamic_cast<Building*>(map[x][y]))
            {
                this->handleBuilding(building);

                cout << "FOUND BASE OBJECT!\n";

            }else if (auto *character = dynamic_cast<Character*>(map[x][y]))
            {
                cout << "FOUND CHARACTER OBJECT!\n";
                this->handleCharacter(character);

            }else if (map[x][y] == nullptr)
            {
                continue;
            }
            else
            {
                throw logic_error("UNRECOGNIZED OBJECT ON THE MAP!");
            }
        }
    }
}

void World::handleCharacter(Character *character)
{
    if (Knight *knight = dynamic_cast<Knight*>(character))
    {
        /// TODO handle Character object - move, action and other
    }
}

void World::handleBuilding(Building *building)
{
    if (Base *base = dynamic_cast<Base*>(building))
    {
        // TODO handle base object - create_object where choose is possible if players has gold
    }else
    {
        return;
    }
}


void World::setInstance(Instance *instance, int pos_x, int pos_y)
{
    this->map[pos_x][pos_y] = instance;
}




/*
 * Getters and setters
 */

Instance *World::getField(int x, int y)
{
    return this->map[x][y];
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




/*
 * Map Functions
 */

void World::createMap() // remember to delete all map objects
{

    this->map = new Instance **[this->map_size_x];

    for (int x = 0; x < this->map_size_x; x++)
    {
        this->map[x] = new Instance * [this->map_size_y];
    }

    for (int x = 0; x < map_size_x; x++)
    {
        for (int y = 0; y < map_size_y; y++)
        {
            map[x][y] = nullptr;
        }
    }
}

void World::displayMap()
/*
 * Displaying map in command line.
 * 0,0 is the left up corner
 */
{
    // display first index row
    for (int i = 0; i < map_size_x; i++)
    {
        if (i == 0)
        {
            cout << "     " << i;
        }
        else if (i < 10)
        {
            cout << "    " << i;
        }
        else
        {
            cout << "   " << i;
        }
    }

    cout << "\n";

    // display rows
    for (int y = 0; y < map_size_y; y++)
    {
        if (y < 10)
        {
            cout << y << "  ";
        }
        else
        {
            cout << y << " ";
        }

        for (int x = 0; x < map_size_x; x++)
        {
            if (x == 0 && y == 0)
            {
                cout << "  M  ";
                continue;
            }

            if (getField(x, y) == nullptr)
            {
                cout << "  0  ";
            }
            else
            {
                // cout << "  " << getSymbol() << "  ";
            }
        }

        cout << endl;
    }
}

/*
 * Menu options, static func
 */

char World::displayMenu()
{
    char option;

    do
    {
//        system("clear"); // TODO CHANGE TO WORK ON LINUX
         system("cls");

        cout << "----- MAIN MENU -----" << "\n";
        cout << " N - Create new game " << "\n";
        cout << " L - Load game       " << "\n";
        cout << " I - Game info       " << "\n";
        cout << " Q - Quit game       " << "\n";

        cout << "\nChoose option: ";

        option = getch();
        option = toupper(option);

        if (option != 'N' && option != 'L' && option != 'Q' && option != 'I')
        {
            system("cls");
            cout << "\nInvalid option. Please try again.";
            Sleep(1000);
        }

    } while (option != 'N' && option != 'L' && option != 'Q' && option != 'I');

    return option;
}

void World::displayGameInfo()
{
    system("cls");

    cout << "------ WAR GAME! ------" << "\n";
    cout << "-----------------------" << "\n\n";
    cout << "-- GAME DESCRIPTION ---" << "\n";
    cout << "This game was created for interview...\n";
    cout << "\n\n";
    cout << "------- AUTHOR --------" << "\n";
    cout << "    MICHAL DUDZIAK     " << "\n\n\n";

    cout << "Press enter to exit info: ";
    getch();
}