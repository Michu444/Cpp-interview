#ifndef INTERVIEW_SETTINGSREADER_H
#define INTERVIEW_SETTINGSREADER_H
#include <string>
#include <fstream>
#include <iostream>


class SettingsReader
{
private:
    std::string pathToMap;
    std::string pathToOrders;
    std::string pathToStatus;

public:

    SettingsReader();

    char** readMap();

};


#endif
