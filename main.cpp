#include "World.h"
#include "utils/SettingsReader.h"
#include <iostream>
#include <conio.h>

using namespace std;

#define ENTER 13
#define Q 113
#define N 110

void display_menu()
{
    cout << "----- MAIN MENU -----" << "\n";
    cout << " N - Create new game " << "\n";
    cout << " L - Load game       " << "\n";
    cout << " Q - Quit game       " << "\n";

}

int main()
{
    char option;
    World *world = nullptr;

    do
    {
        option = World::displayMenu();

        if (option == 'N')
        {
            world = new World(12, 12);

            //        world.createMap();

            //        world.displayMap();

        } else if (option == 'L')
        {
            SettingsReader settingsReader;

            char **map = settingsReader.readMap();

            cout << map;

            // TODO second constructor to prepare world with setted settings where settings are converted to correct data.
            // World world(map, orders, status); <-- inside all should be converted to correct vaules.

        } else if (option == 'Q')
        {
            system("cls");
            cout << "GOOD BYE!";
            getch();
            exit(0);
        } else if (option == 'I')
        {
            World::displayGameInfo();
        } else
        {
            throw runtime_error("PROGRAM CRASHED! PLEASE RUN GAME AGAIN");
        }
    } while (option != 'N' && option != 'L');
/*
 * MAIN PROGRAM LOOP
 */
    do
    {
        world->makeRound();


    } while (!world->getGameEnd());

    system("cls");
    cout << "---THANK YOU FOR GAME!---" << "\n";
    getchar();

    return 0;
}
