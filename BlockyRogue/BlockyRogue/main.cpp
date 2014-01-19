#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Projectile.h"
#include <iostream>
#include "ConfigurationHandler.hpp"
#include <list>
#include "EnemyManager.h"
#include "SceneManager.h"
#include "MainGameScene.hpp"

using namespace sf;

ConfigurationHandler config;

int main()
{

//==========================================================================
// Primary Setup
//
	sf::VideoMode desktopResolution = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(desktopResolution, "BlockyRogue!", sf::Style::Fullscreen);
	sf::View view(sf::Vector2f(350, 300), sf::Vector2f(desktopResolution.width, desktopResolution.height));
	window.setView(view);

    SceneManager sceneManager;
    sceneManager.pushScene((Scene*)(new MainGameScene()));
   
	sf::Clock clock;

//==========================================================================
// Main Game Loop
//

    while (window.isOpen())
    {
		sf::Time elapsed = clock.restart();
        sf::Event event;

        if(sf::Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        sceneManager.update(elapsed.asSeconds());
        sceneManager.draw(&window, view);
    }

    return 0;
}
