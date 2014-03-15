#include "UpgradeManager.hpp"

UpgradeManager::UpgradeManager()
{
    srand(time(NULL));
    loadUpgrades();
}

UpgradeManager::~UpgradeManager()
{
    while(!playerUpgradesToApply.empty()) delete playerUpgradesToApply.front(), playerUpgradesToApply.pop_front();
    while(!appliedPlayerUpgrades.empty()) delete appliedPlayerUpgrades.front(), appliedPlayerUpgrades.pop_front();
    while(!availablePlayerUpgrades.empty()) delete availablePlayerUpgrades.front(), availablePlayerUpgrades.pop_front();
    
    while(!enemyUpgradesToApply.empty()) delete enemyUpgradesToApply.front(), enemyUpgradesToApply.pop_front();
    while(!appliedEnemyUpgrades.empty()) delete appliedEnemyUpgrades.front(), appliedEnemyUpgrades.pop_front();
    while(!availableEnemyUpgrades.empty()) delete availableEnemyUpgrades.front(), availableEnemyUpgrades.pop_front();
}

//Get Player Upgrades
std::list<Upgrade*> UpgradeManager::getAppliedPlayerUpgrades()
{
    return appliedPlayerUpgrades;
}
std::list<Upgrade*> UpgradeManager::getPlayerUpgradesToApply()
{
    return playerUpgradesToApply;
}
std::list<Upgrade*> UpgradeManager::getAvailablePlayerUpgrades()
{
    return availablePlayerUpgrades;
}

//Get Enemy Upgrades
std::list<Upgrade*> UpgradeManager::getAppliedEnemyUpgrades()
{
    return appliedEnemyUpgrades;
}
std::list<Upgrade*> UpgradeManager::getEnemyUpgradesToApply()
{
    return enemyUpgradesToApply;
}
std::list<Upgrade*> UpgradeManager::getAvailableEnemyUpgrades()
{
    return availableEnemyUpgrades;
}

//Apply Upgrades
//TODO: Add actual upgrade code for player and enemies. Commented lines located where upgrade code should be.
void UpgradeManager::applyUpgrades(Player *p, EnemyManager *em)
{
    applyPlayerUpgrades(p);
    applyEnemyUpgrades(em);
}
void UpgradeManager::applyPlayerUpgrades(Player *p)
{
    while(!playerUpgradesToApply.empty())
    {
        p->applyUpgrade(*playerUpgradesToApply.front());
        appliedPlayerUpgrades.push_back(playerUpgradesToApply.front());
        playerUpgradesToApply.pop_front();
    }
}
void UpgradeManager::applyEnemyUpgrades(EnemyManager *em)
{
    std::list<Enemy*> *elist = em->getEnemyList();
    while(!enemyUpgradesToApply.empty())
    {
        for (std::list<Enemy*>::iterator it = elist->begin(); it != elist->end(); ++it)
        {
            (*it)->applyUpgrade(*enemyUpgradesToApply.front());
        }
        appliedEnemyUpgrades.push_back(enemyUpgradesToApply.front());
        enemyUpgradesToApply.pop_front();
    }
}

//Readies a random upgrade for both the player and enemies to be applied
void UpgradeManager::readyRandomUpgrade()
{
    if(availablePlayerUpgrades.size() <= 1 || availableEnemyUpgrades.size() <= 1)
    {
        for(int i = 0 ; i < rand()%20; i++)
        {
            generateRandomUpgrade();
        }
    }
    int enemyUpgrade = (rand() % availableEnemyUpgrades.size());
    int playerUpgrade = (rand() % availablePlayerUpgrades.size());
    
    int i = 0;
    for (std::list<Upgrade*>::iterator et = availableEnemyUpgrades.begin(); et != availableEnemyUpgrades.end();)
    {
        if(i == enemyUpgrade)
        {
            enemyUpgradesToApply.push_back(*et);
            et = availableEnemyUpgrades.erase(et);
            break;
        }
        else
        {
            ++et;
            i++;
        }
    }
    i = 0;
    for (std::list<Upgrade*>::iterator it = availablePlayerUpgrades.begin(); it != availablePlayerUpgrades.end();)
    {
        if(i == playerUpgrade)
        {
            playerUpgradesToApply.push_back(*it);
            it = availablePlayerUpgrades.erase(it);
            break;
        }
        else
        {
            ++it;
            i++;
        }
    }
}

//Cancels the upgrade and returns the readied upgrades back to the list of available upgrades
void UpgradeManager::cancelUpgrade()
{
    while(!playerUpgradesToApply.empty())
    {
        availablePlayerUpgrades.push_back(playerUpgradesToApply.front());
        playerUpgradesToApply.pop_front();
    }
    while(!enemyUpgradesToApply.empty())
    {
        availableEnemyUpgrades.push_back(enemyUpgradesToApply.front());
        enemyUpgradesToApply.pop_front();
    }

}

void UpgradeManager::generateRandomUpgrade()
{
    if(rand()%2 == 0)
    {
        availablePlayerUpgrades.push_back(new Upgrade("moveSpeed", (rand()%200)-100));
        availableEnemyUpgrades.push_back(new Upgrade("moveSpeed", (rand()%200)-100));
    }else
    {
        availablePlayerUpgrades.push_back(new Upgrade("health", (rand()%200)-100));
        availableEnemyUpgrades.push_back(new Upgrade("health", (rand()%200)-100));
    }
}

void UpgradeManager::loadUpgrades()
{
    std::string path = getResourcePath("")+"upgrades.ini";
    std::ifstream configFile(path.c_str());
    std::string currentLine;
    
    if(configFile.is_open())
    {
        while(std::getline(configFile, currentLine))
        {
            std::stringstream stream(currentLine);
            char pore;
            std::string type;
            double amount;
            stream >> pore >> type >> amount;
            if(pore == 'p')
                availablePlayerUpgrades.push_back(new Upgrade(type, amount));
            if(pore == 'e')
                availableEnemyUpgrades.push_back(new Upgrade(type, amount));
        }
    }
    configFile.close();
}


