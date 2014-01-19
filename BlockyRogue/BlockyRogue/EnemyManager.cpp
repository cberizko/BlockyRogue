
#include "EnemyManager.h"
#include <iostream>

EnemyManager::EnemyManager()
{
}

void EnemyManager::update()
{
    for(int i = 0; i < enemies.size(); i++)
    {
        enemies[i]->update();
    }
}

void EnemyManager::draw(sf::RenderWindow* window)
{
    for(int i = 0; i < enemies.size(); i++)
    {
        enemies[i]->draw(window);
    }
}


void EnemyManager::addEnemy(sf::Vector2f v2f)
{
    enemies.push_back(new Enemy(v2f));
}
