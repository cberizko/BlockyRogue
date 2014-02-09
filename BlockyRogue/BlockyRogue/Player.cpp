#include "Player.hpp"
#include <iostream>
#include "getResourcePath.hpp"

Player::Player()
{
	velocity = new sf::Vector2f();
	sf::VideoMode currentResolution = sf::VideoMode::getDesktopMode();
    //initGraphics("Player.png");
    //sprite.setPosition(100.f,100.f);
	//sprite.setScale(currentResolution.width / 1920.0, currentResolution.height / 1080.0);

    //Creates the players dynamic shape
    initShape(config["PLAYER_SHAPE_STARTING_VERTICES"], 
              config["PLAYER_SHAPE_BASE_RADIUS"], 
              config["PLAYER_SHAPE_VARIANCE"]);

    health = config["PLAYER_MAX_HEALTH"];
    moveSpeed = config["PLAYER_MOVE_SPEED"];
}

Player::~Player()
{
}

void Player::update(float elapsedTime)
{
	velocity->x = 0.f;
	velocity->y = 0.f;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		sprite.move(moveSpeed * elapsedTime, 0);
        for(int i = 0; i < shape.getVertexCount(); i++)
        {
            shape[i].position += sf::Vector2f(moveSpeed*elapsedTime, 0);
        }
		velocity->x = moveSpeed;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		sprite.move(-moveSpeed * elapsedTime, 0);
        for(int i = 0; i < shape.getVertexCount(); i++)
        {
            shape[i].position += sf::Vector2f(-moveSpeed*elapsedTime, 0);
        }
		velocity->x = -moveSpeed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		sprite.move(0, -moveSpeed * elapsedTime);
        for(int i = 0; i < shape.getVertexCount(); i++)
        {
            shape[i].position += sf::Vector2f(0, -moveSpeed*elapsedTime);
        }
		velocity->y = -moveSpeed;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		sprite.move(0, moveSpeed * elapsedTime);
        for(int i = 0; i < shape.getVertexCount(); i++)
        {
            shape[i].position += sf::Vector2f(0, moveSpeed*elapsedTime);
        }
		velocity->y = moveSpeed;
	}
}

void Player::draw(sf::RenderWindow* window)
{
    window->draw(shape);
}

void Player::initShape(int verts, int radius, int variance)
{
    //Required Random Seed for the player shape generation
    std::srand(std::time(NULL));

    shape = sf::VertexArray(sf::TrianglesFan, verts+1);

    for(int i = 0; i < verts+1; i++)
    {
        //Equation of a Circle: (parametric coordinates)
        //for a circle with origin (j, k) and radius r:
        //x(t) = r cos(t) + j       y(t) = r sin(t) + k

        int radius_offset = std::rand()%variance; 
        double location = i*((2*PI)/verts);

        shape[i].position = sf::Vector2f((radius+radius_offset)*std::cos(location), (radius+radius_offset)*std::sin(location));

        shape[i].color = sf::Color::Red;
    }
}

sf::Vector2f* Player::getVelocity()
{
	return velocity;
}
