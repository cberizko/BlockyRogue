#ifndef _CONFIGURATIONHANDLER_H
#define _CONFIGURATIONHANDLER_H

#include <iostream>
#include <map>
#include <string>
#include <fstream>

#define PLAYER_MOVE_SPEED 200

class ConfigurationHandler
{
    public:
        ConfigurationHandler();
    private:
        std::map<std::string, int> configData;
        void parseLine(std::string line);
};


#endif
