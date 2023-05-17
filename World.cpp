#include <iostream>
#include <conio.h>
#include <windows.h>
#include "World.h"
#include "utils/SettingsReader.h"
#include "Instance.h"
#include "buildings/Base.h"

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
    if (round == 2000)
    {
        cout << "END GAME!\n";
        // this->endGame();
        gameEnd = true;
        return;
    }

    this->increaseRound();
    cout << "Round: " << this->getRound() << "\n";





    // po kolei ma obslugiwac wszystkie pola na planszy i jesli jest na nim obiekt to wykonywad dla opcje: ruch albo akcja.


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

bool World::getGameEnd()
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

    for (int i = 0; i < this->map_size_x; i++)
    {
        this->map[i] = new Instance * [this->map_size_y];
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