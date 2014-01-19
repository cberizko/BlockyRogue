#ifndef _MAINGAMESCENE_HPP
#define _MAINGAMESCENE_HPP

#include "Scene.hpp"
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Projectile.h"
#include <iostream>
#include "ConfigurationHandler.hpp"
#include <list>
#include "EnemyManager.h"

class MainGameScene: Scene
{
    public:
        MainGameScene();
        ~MainGameScene();
        void update(float elapsedTime);
        void draw(sf::RenderWindow* window, sf::View view);

    private:
        float timeOut;
        Player *p;
        std::list<Projectile*> projectiles;
        EnemyManager *enemies;
        sf::Clock clock;
};

#endif
