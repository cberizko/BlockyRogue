#ifndef _ENEMYMANAGER_HPP
#define _ENEMYMANAGER_HPP
#include <SFML/Graphics.hpp>
#include <vector>
#include "Enemy.hpp"

class EnemyManager
{
private:
    std::vector<Enemy*> enemies;
public:
    EnemyManager();
    void update(float elapsed);
    void draw(sf::RenderWindow* window);
    
    void addEnemy(sf::Vector2f v2f);
};

#endif
