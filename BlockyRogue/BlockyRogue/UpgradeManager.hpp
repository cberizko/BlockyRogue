#ifndef __BlockyRogue__UpgradeManager__
#define __BlockyRogue__UpgradeManager__

#include <list>
#include <stdlib.h>
#include <time.h>
#include "Upgrade.hpp"
#include "Player.hpp"
#include "EnemyManager.hpp"
#include "getResourcePath.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

class UpgradeManager
{
protected:
    //Player Upgrade Lists
    std::list<Upgrade*> appliedPlayerUpgrades;
    std::list<Upgrade*> playerUpgradesToApply;
    std::list<Upgrade*> availablePlayerUpgrades;
    
    //Enemy Upgrade Lists
    std::list<Upgrade*> appliedEnemyUpgrades;
    std::list<Upgrade*> enemyUpgradesToApply;
    std::list<Upgrade*> availableEnemyUpgrades;
    
public:
    UpgradeManager();
    ~UpgradeManager();
    
    //Get Player Upgrades
    std::list<Upgrade*> getAppliedPlayerUpgrades();
    std::list<Upgrade*> getPlayerUpgradesToApply();
    std::list<Upgrade*> getAvailablePlayerUpgrades();
    
    //Get Enemy Upgrades
    std::list<Upgrade*> getAppliedEnemyUpgrades();
    std::list<Upgrade*> getEnemyUpgradesToApply();
    std::list<Upgrade*> getAvailableEnemyUpgrades();
    
    //Apply Upgrades
    void applyUpgrades(Player *p, EnemyManager *em);
    void applyPlayerUpgrades(Player *p);
    void applyEnemyUpgrades(EnemyManager *em);
    void applyEnemyUpgrade(Enemy *e);
    
    std::ostringstream displayPlayerUpgradesToApply();
    std::ostringstream displayEnemyUpgradesToApply();
    
    //Readies a random upgrade to apply (would be called on level up)
    void readyRandomUpgrade();
    void cancelUpgrade();
    
    //Todo: Add function to generate upgrades and to create upgrades from a list/ini
    void generateRandomUpgrade();
    void loadUpgrades();
};

#endif 