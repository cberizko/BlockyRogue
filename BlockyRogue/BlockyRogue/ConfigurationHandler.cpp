#include "ConfigurationHandler.hpp"
#include "getResourcePath.hpp"

ConfigurationHandler::ConfigurationHandler()
{
    std::string path = getResourcePath("")+"config.ini";
    std::ifstream configFile(path.c_str());
    parseFile(&configFile);
}

ConfigurationHandler::ConfigurationHandler(std::string pathToFile)
{
    std::ifstream configFile(pathToFile.c_str());
    parseFile(&configFile);
}

//Reads in each line in the config file, and parses it.
void ConfigurationHandler::parseFile(std::ifstream* fileStream)
{
    std::string currentLine;

    if(fileStream->is_open())
    {
        while(std::getline(*fileStream, currentLine))
        {
            parseLine(currentLine);
        }
    }
    fileStream->close();
}

void ConfigurationHandler::parseLine(std::string line)
{
    //Check to make sure it is not a comment or an empty line
    if(line.c_str()[0] != '#' && !line.empty())
    {
        //Initialize variable to capture key and value
        std::string key = "";
        double value = 0;

        //Create a stringstream to parse the passed in line
        std::stringstream stream(line);

        //Parse line in the order "Key Value"
        stream >> key >> value;

        //Store key and value into map
        configData.insert(std::pair<std::string, double>(key, value));
    }
}

double ConfigurationHandler::operator[](std::string s) const
{
    return configData.at(s);
}

