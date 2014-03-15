#ifndef __BlockyRogue__Upgrade__
#define __BlockyRogue__Upgrade__

#include <iostream>
#include <string>

class Upgrade
{
public:
    Upgrade(std::string upgradeType, double upgradeAmount);
    ~Upgrade();
    
    std::string getType();
    double getAmount();
    
protected:
    std::string type;
    double amount;

};

#endif
