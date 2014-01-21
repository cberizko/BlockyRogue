#ifndef _ENEMYMANAGER_HPP
#define _ENEMYMANAGER_HPP
#include <SFML/Graphics.hpp>
#include <list>
#include "Enemy.hpp"
#include "Player.hpp"
#include <stdlib.h>
#include <time.h>

class EnemyManager
{
private:
    std::list<Enemy*> enemies;
    double maxEnemies;
    double despawnRange;
public:
    EnemyManager();
    void update(Player player, float elapsedTime);
    void draw(sf::RenderWindow* window);
    
    void addEnemy(sf::Vector2f v2f);
    void despawn(Player player);
    void spawn(Player player);
};

#endif
