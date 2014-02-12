#ifndef _MAINGAMESCENE_HPP
#define _MAINGAMESCENE_HPP

#include "Scene.hpp"
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Enemy.hpp"
#include "PlayerProjectile.hpp"
#include "EnemyProjectile.hpp"
#include <iostream>
#include "ConfigurationHandler.hpp"
#include <list>
#include "EnemyManager.hpp"


class MainGameScene: Scene
{
    public:
        MainGameScene();
        ~MainGameScene();
        void update(float elapsedTime);
        void draw(sf::RenderWindow* window, sf::View view);

        sf::VertexArray testShape;

    private:
		sf::Font blockyFont;
		sf::Text enemyKillCounterText;
		int enemyKillsToLevel;
        float timeOut;
        Player *p;
        std::list<Projectile*> projectiles;
        EnemyManager *enemies;
        sf::Clock clock;
};

#endif
