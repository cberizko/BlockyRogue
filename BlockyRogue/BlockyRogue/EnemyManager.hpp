#ifndef _ENEMYMANAGER_HPP
#define _ENEMYMANAGER_HPP
#include <SFML/Graphics.hpp>
#include <list>
#include "EnemySquare.hpp"
#include "EnemyTriangle.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "Projectile.hpp"
#include <stdlib.h>
#include <time.h>

class UpgradeManager;
class EnemyManager
{
private:
    std::list<Enemy*> enemies;
    double maxEnemies;
    double despawnRange;
	int numEnemiesKilled;
    UpgradeManager *upgradeManager;
public:
    EnemyManager(UpgradeManager *um, std::list<Projectile*> *proj);
    ~EnemyManager();
	int getEnemiesKilled();
	void setEnemiesKilled(int enemiesKilled);
    void update(Player *player, float elapsedTime);
    void draw(sf::RenderWindow* window);
    
    void addEnemy(sf::Vector2f v2f, Player *p);
    void despawn(Player *player);
    void spawn(Player *player);
    std::list<Enemy*>* getEnemyList();
	std::list<Projectile*> *projectiles;
};

#endif
