#ifndef _CONFIGURATIONHANDLER_HPP
#define _CONFIGURATIONHANDLER_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>

class ConfigurationHandler
{
    public:
        ConfigurationHandler();
        ConfigurationHandler(std::string pathToFile);
        
        double operator [](std::string s) const;

    private:
        std::map<std::string, double> configData;
        void parseFile(std::ifstream *fileStream);
        void parseLine(std::string line);
};


#endif
