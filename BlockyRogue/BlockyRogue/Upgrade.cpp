#include "Upgrade.hpp"


Upgrade::Upgrade(std::string upgradeType, double upgradeAmount, std::string upgradeMod)
{
    type = upgradeType;
    amount = upgradeAmount;
    mod = upgradeMod;
}
Upgrade::~Upgrade()
{
}

std::string Upgrade::getType()
{
    return type;
}
double Upgrade::getAmount()
{
    return amount;
}
std::string Upgrade::getMod()
{
    return mod;
}