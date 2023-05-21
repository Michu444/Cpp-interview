#include "World.h"
#include "utils/SettingsReader.h"
#include <iostream>
#include <conio.h>

void display_menu()
{
    std::cout << "----- MAIN MENU -----" << "\n";
    std::cout << " N - Create new game " << "\n";
    std::cout << " L - Load game       " << "\n";
    std::cout << " Q - Quit game       " << "\n";

}

int main()
{
    char option;
    World *world = nullptr;

    // MAIN MENU LOOP
    do // TODO CHANGE ON SWITCH WITH GETCH
    {
//        option = World::displayMenu(); //TODO UNCOMMENT
        option = 'N';

        if (option == 'N')
        {
            world = new World(12, 12);

        } else if (option == 'L')
        {
            SettingsReader settingsReader;

            world = new World(12,12); // TODO

            char **map = settingsReader.readMap();

            std::cout << map;

            // TODO second constructor to prepare world with setted settings where settings are converted to correct data.
            // World world(map, orders, status); <-- inside all should be converted to correct vaules.

        } else if (option == 'Q')
        {
            system("cls");
            std::cout << "GOOD BYE!";
            getch();
            exit(0);
        } else if (option == 'I')
        {
            World::displayGameInfo();
        } else
        {
            throw std::runtime_error("PROGRAM CRASHED! PLEASE RUN GAME AGAIN");
            exit(1);
        }
    } while (option != 'N' && option != 'L');

    world->displayMap();

    // MAIN GAME LOOP
    do
    {
        world->makeRound();
        getch();

    } while (!world->getGameStatus());

    system("cls");
    std::cout << "---THANK YOU FOR GAME!---" << "\n";
    getchar();

    return 0;
}
