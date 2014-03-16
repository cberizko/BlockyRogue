#ifndef __BlockyRogue__Upgrade__
#define __BlockyRogue__Upgrade__

#include <iostream>
#include <string>

class Upgrade
{
public:
    Upgrade(std::string upgradeType, double upgradeAmount, std::string upgradeMod);
    ~Upgrade();
    
    std::string getType();
    double getAmount();
    std::string getMod();
    
protected:
    std::string type;
    double amount;
    std::string mod;

};

#endif
