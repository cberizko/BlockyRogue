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

    /*
	float timeOut = 0.f;

    Player *p = new Player();
	std::list<Projectile*> projectiles;
    
    EnemyManager *enemies = new EnemyManager();
    enemies->addEnemy(sf::Vector2f(300.f, 100.f));
    enemies->addEnemy(sf::Vector2f(100.f, 300.f));
    enemies->addEnemy(sf::Vector2f(50.f, 50.f));

	window.setMouseCursorVisible(false);
    */
    
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

        //==================================================================
        // Capture Input 
        //
        /* 
		if(timeOut > 0) //If shot is still on cool down
	    {
            timeOut -= elapsed.asSeconds();
        }
		else //Else accept key input for shooting
		{
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				projectiles.push_back(new Projectile(sf::Vector2f(p->getPosition().x + p->getBounds().width, 
					p->getPosition().y + p->getBounds().height / 2), sf::Vector2f(300, 0)));
				timeOut = .5f;
			} 
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				projectiles.push_back(new Projectile(sf::Vector2f(p->getPosition().x, 
					p->getPosition().y + p->getBounds().height / 2), sf::Vector2f(-300, 0)));
				timeOut = .5f;
			}
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				projectiles.push_back(new Projectile(sf::Vector2f(p->getPosition().x + p->getBounds().width / 2, 
					p->getPosition().y), sf::Vector2f(0, -300)));
				timeOut = .5f;
			}
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				projectiles.push_back(new Projectile(sf::Vector2f(p->getPosition().x + p->getBounds().width / 2, 
					p->getPosition().y + p->getBounds().height), sf::Vector2f(0, 300)));
				timeOut = .5f;
			}
		}

		if(sf::Keyboard::isKeyPressed((sf::Keyboard::Escape)))
			window.close();


        //==================================================================
        // Update 
        //
        
		for (std::list<Projectile*>::iterator it = projectiles.begin(); it != projectiles.end();)
		{
			(*it)->update(elapsed.asSeconds());
			if((*it)->dead)
			{
				delete *it;
				it = projectiles.erase(it);
			}
			else
			{
				++it;
			}
		}
        
		p->update(elapsed.asSeconds());
		enemies->update(elapsed.asSeconds());


        //==================================================================
        // Draw 
        //
        
        p->draw(&window);
        enemies->draw(&window);
       
        for (std::list<Projectile*>::iterator it = projectiles.begin(); it != projectiles.end();++it)
		{
			(*it)->draw(&window);
		}

		view.setCenter(sf::Vector2f(p->getPosition().x + p->getBounds().width / 2, p->getPosition().y + p->getBounds().height / 2));
		window.setView(view);
        window.display();
        window.clear(Color(0, 0, 0, 255));
        */

        sceneManager.draw(&window, view);
    }

    return 0;
}
