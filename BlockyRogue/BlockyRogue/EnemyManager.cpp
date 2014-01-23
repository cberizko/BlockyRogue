#include "EnemyManager.hpp"
#include <iostream>

EnemyManager::EnemyManager()
{
    maxEnemies = config["ENEMYMANAGER_MAX_ENEMIES"];
    despawnRange = config["ENEMYMANAGER_DESPAWN_RANGE"];
    srand(time(NULL));
}

void EnemyManager::update(Player player, float elapsedTime)
{
    for (std::list<Enemy*>::iterator it = enemies.begin(); it != enemies.end();++it)
    {
        (*it)->update(elapsedTime);

        if((*it)->getHealth() <= 0)
        {
            delete *it;
            it = enemies.erase(it);
        }
    }
    
    despawn(player);
    spawn(player);
}

void EnemyManager::draw(sf::RenderWindow* window)
{
    for (std::list<Enemy*>::iterator it = enemies.begin(); it != enemies.end();++it)
    {
        (*it)->draw(window);
    }
}


void EnemyManager::addEnemy(sf::Vector2f v2f)
{
    enemies.push_back(new Enemy(v2f));
}

void EnemyManager::despawn(Player player)
{
    sf::VideoMode currentResolution = sf::VideoMode::getDesktopMode();
    int sWidth = currentResolution.width;
    int sHeight = currentResolution.height;
    
    int viewX = player.getPosition().x;
    int viewY = player.getPosition().y;
    
    for (std::list<Enemy*>::iterator it = enemies.begin(); it != enemies.end();)
    {
        if((*it)->getPosition().x-viewX >= (sWidth/2)*despawnRange)
        {
            delete *it;
            it = enemies.erase(it);
        }
        else if((*it)->getPosition().x-viewX <= (sWidth/2)*(-1*despawnRange))
        {
            delete *it;
            it = enemies.erase(it);
        }
        else if((*it)->getPosition().y-viewY >= (sHeight/2)*despawnRange)
        {
            delete *it;
            it = enemies.erase(it);
        }
        else if((*it)->getPosition().y-viewY <= (sHeight/2)*(-1*despawnRange))
        {
            delete *it;
            it = enemies.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void EnemyManager::spawn(Player player)
{
    if(enemies.size() < maxEnemies)
    {
        sf::VideoMode currentResolution = sf::VideoMode::getDesktopMode();
        int sWidth = currentResolution.width;
        int sHeight = currentResolution.height;
    
        int viewX = player.getPosition().x;
        int viewY = player.getPosition().y;
    
        int spawnX = viewX;
        int spawnY = viewY;
        int x = 0;
        int y = 0;
        
        while((spawnX > viewX-(sWidth/2) && spawnX < viewX+(sWidth/2)) &&
              (spawnY > viewY-(sHeight/2) && spawnY < viewY+(sHeight/2)))
        {
            x = (int)((sWidth/2)*despawnRange)*2;
            y = (int)((sHeight/2)*despawnRange)*2;
            spawnX = ((rand() % x)+viewX)-(x/2);
            spawnY = ((rand() % y)+viewY)-(x/2);
        }

        enemies.push_back(new Enemy(sf::Vector2f(spawnX, spawnY)));
    }
    
}

std::list<Enemy*> EnemyManager::getEnemyList()
{
    return enemies;
}
