#ifndef _ENEMYMANAGER_H
#define _ENEMYMANAGER_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "Enemy.h"

class EnemyManager
{
private:
    std::vector<Enemy*> enemies;
public:
    EnemyManager();
    void update();
    void draw(sf::RenderWindow* window);
    
    void addEnemy(sf::Vector2f v2f);
};

#endif