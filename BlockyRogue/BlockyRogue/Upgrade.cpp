#include "Upgrade.hpp"


Upgrade::Upgrade(std::string upgradeType, double upgradeAmount)
{
    type = upgradeType;
    amount = upgradeAmount;
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