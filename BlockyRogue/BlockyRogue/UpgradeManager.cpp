#include "UpgradeManager.hpp"

UpgradeManager::UpgradeManager()
{
    srand(time(NULL));
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
        //Upgrade code goes here
        //player->upgrade(playerUpgradesToApply->front());
        appliedPlayerUpgrades.push_back(playerUpgradesToApply.front());
        playerUpgradesToApply.pop_front();
    }
}
void UpgradeManager::applyEnemyUpgrades(EnemyManager *em)
{
    while(!enemyUpgradesToApply.empty())
    {
        for (std::list<Enemy*>::iterator it = ((std::list<Enemy*>)em->getEnemyList()).begin(); it != ((std::list<Enemy*>)em->getEnemyList()).end();++it)
        {
            //Upgrade code goes here
            //(*it)->upgrade(enemyUpgradesToApply->front());
        }
        appliedEnemyUpgrades.push_back(enemyUpgradesToApply.front());
        enemyUpgradesToApply.pop_front();
    }
}

//Readies a random upgrade for both the player and enemies to be applied
void UpgradeManager::readyRandomUpgrade()
{
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


