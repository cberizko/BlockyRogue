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

void UpgradeManager::applyEnemyUpgrade(Enemy *e)
{
    for (std::list<Upgrade*>::iterator et = appliedEnemyUpgrades.begin(); et != appliedEnemyUpgrades.end();)
    {
        e->applyUpgrade(*(*et));
        ++et;
    }
}

//Readies a random upgrade for both the player and enemies to be applied
void UpgradeManager::readyRandomUpgrade()
{
    int r = 1;
    while(r >= 1)
    {
        r--;
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
        r = (rand()%100);
        if(r >= 25){ r = 0; }
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
    

        for(int i = 0 ; i < rand()%20; i++)
        {
            generateRandomUpgrade();
        }

}

void UpgradeManager::generateRandomUpgrade()
{
    /*
     Double/Decimal Template
     if(uType == #)
     {
     availablePlayerUpgrades.push_back(new Upgrade("projectileRange", ((double)(rand()%100)/100)));
     availableEnemyUpgrades.push_back(new Upgrade("projectileRange", ((double)(rand()%100)/100)));
     }
     
     int Template
     if(uType == #)
     {
     availablePlayerUpgrades.push_back(new Upgrade("projectileRange", (rand()%(max-min))+min);
     availableEnemyUpgrades.push_back(new Upgrade("projectileRange", (rand()%(max-min))+min);
     }
     */
    
    
    int uType = rand()%5;
    if(uType == 0)
    {
        availablePlayerUpgrades.push_back(new Upgrade("moveSpeed", (rand()%200)-100, "+"));
        availableEnemyUpgrades.push_back(new Upgrade("moveSpeed", (rand()%200)-100, "+"));
    }
    if(uType == 1)
    {
        availablePlayerUpgrades.push_back(new Upgrade("health", (rand()%10)-5, "+"));
        availableEnemyUpgrades.push_back(new Upgrade("health", (rand()%10)-5, "+"));
    }
    if(uType == 2)
    {
        availablePlayerUpgrades.push_back(new Upgrade("projectileRange", ((double)(rand()%20)-10), "+"));
        availableEnemyUpgrades.push_back(new Upgrade("projectileRange", ((double)(rand()%20)-10), "+"));
    }
    if(uType == 3)
    {
        availablePlayerUpgrades.push_back(new Upgrade("projectileDelay", ((double)(rand()%100)/100)-0.5, "+"));
        availableEnemyUpgrades.push_back(new Upgrade("projectileDelay", ((double)(rand()%100)/100)-0.5, "+"));
    }
    if(uType == 4)
    {
        availablePlayerUpgrades.push_back(new Upgrade("projectileDamage", ((double)(rand()%10)-5), "+"));
        availableEnemyUpgrades.push_back(new Upgrade("projectileDamage", ((double)(rand()%10)-5), "+"));
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
            std::string mod;
            stream >> pore >> type >> mod >> amount;
            if(pore == 'p')
                availablePlayerUpgrades.push_back(new Upgrade(type, amount, mod));
            if(pore == 'e')
                availableEnemyUpgrades.push_back(new Upgrade(type, amount, mod));
        }
    }
    configFile.close();
}

std::string UpgradeManager::displayPlayerUpgradesToApply()
{
    std::ostringstream playerUpgradeString;
    playerUpgradeString << "Player Upgrades\n";
    for (std::list<Upgrade*>::iterator it = playerUpgradesToApply.begin(); it != playerUpgradesToApply.end();)
    {
        playerUpgradeString << (*(*it)).getType() << " " << (*(*it)).getMod() << " " << (*(*it)).getAmount() << "\n";
        ++it;
    }
    return playerUpgradeString.str();
}
std::string UpgradeManager::displayEnemyUpgradesToApply()
{
    std::ostringstream enemyUpgradeString;
    enemyUpgradeString << "Enemy Upgrades\n";
    for (std::list<Upgrade*>::iterator it = enemyUpgradesToApply.begin(); it != enemyUpgradesToApply.end();)
    {
        enemyUpgradeString << (*(*it)).getType() << " " << (*(*it)).getMod() << " " << (*(*it)).getAmount() << "\n";
        ++it;
    }
    return enemyUpgradeString.str();
}


