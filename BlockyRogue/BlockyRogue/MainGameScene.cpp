#include "MainGameScene.hpp"

MainGameScene::MainGameScene(): Scene("Main Game Scene")
{
    timeOut = 0.f;

    p = new Player();

    enemies = new EnemyManager();
}

MainGameScene::~MainGameScene()
{
}

void MainGameScene::update(float elapsedTime)
{
    //==================================================================
    // Capture Input 
    //

    if(timeOut > 0) //If shot is still on cool down
    {
        timeOut -= elapsedTime;
    }
    else //Else accept key input for shooting
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            projectiles.push_back(new Projectile(sf::Vector2f(p->getPosition().x + p->getBounds().width, 
				p->getPosition().y + p->getBounds().height / 2), sf::Vector2f(config["PROJECTILE_BASE_VELOCITY"], 0) + *p->getVelocity(),
				Projectile::RIGHT));
            timeOut = config["PROJECTILE_DELAY"];
        } 
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
			projectiles.push_back(new Projectile(sf::Vector2f(p->getPosition().x, 
                p->getPosition().y + p->getBounds().height / 2), sf::Vector2f(-config["PROJECTILE_BASE_VELOCITY"], 0) + *p->getVelocity(),
				Projectile::LEFT));
            timeOut = config["PROJECTILE_DELAY"];
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            projectiles.push_back(new Projectile(sf::Vector2f(p->getPosition().x + p->getBounds().width / 2, 
                p->getPosition().y), sf::Vector2f(0, -config["PROJECTILE_BASE_VELOCITY"]) + *p->getVelocity(),
				Projectile::UP));
            timeOut = config["PROJECTILE_DELAY"];
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
                projectiles.push_back(new Projectile(sf::Vector2f(p->getPosition().x + p->getBounds().width / 2, 
                p->getPosition().y + p->getBounds().height), sf::Vector2f(0, config["PROJECTILE_BASE_VELOCITY"]) + *p->getVelocity(),
				Projectile::DOWN));
            timeOut = config["PROJECTILE_DELAY"];
        }
    }


    //==================================================================
    // Update 
    //
    
    for (std::list<Projectile*>::iterator it = projectiles.begin(); it != projectiles.end();)
    {
        (*it)->update(elapsedTime, enemies);
        
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
    
    p->update(elapsedTime);
    enemies->update(*p, elapsedTime);
}

void MainGameScene::draw(sf::RenderWindow* window, sf::View view)
{
    //==================================================================
    // Draw 
    //
    
    p->draw(window);
    enemies->draw(window);
   
    for (std::list<Projectile*>::iterator it = projectiles.begin(); it != projectiles.end();++it)
    {
        (*it)->draw(window);
    }

    view.setCenter(sf::Vector2f(p->getPosition().x + p->getBounds().width / 2, p->getPosition().y + p->getBounds().height / 2));
    window->setView(view);
    window->display();
    window->clear(sf::Color(0, 0, 0, 255));
}
