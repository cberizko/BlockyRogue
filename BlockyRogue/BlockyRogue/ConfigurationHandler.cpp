#include "ConfigurationHandler.hpp"

ConfigurationHandler::ConfigurationHandler()
{
    std::string currentLine;
    std::ifstream configFile("config.ini");

    if(configFile.is_open())
    {
        while(std::getline(configFile, currentLine))
        {
            parseLine(currentLine);
        }
    }
}

void ConfigurationHandler::parseLine(std::string)
{

}
