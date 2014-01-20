#ifndef _ENEMYMANAGER_HPP
#define _ENEMYMANAGER_HPP
#include <SFML/Graphics.hpp>
#include <list>
#include "Enemy.h"

class EnemyManager
{
private:
    std::list<Enemy*> enemies;
    int maxEnemies;
public:
    EnemyManager();
    void update(sf::View view);
    void draw(sf::RenderWindow* window);
    
    void addEnemy(sf::Vector2f v2f);
    void despawn(sf::View view);
    void spawn();
};

#endif
