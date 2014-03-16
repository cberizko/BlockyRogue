#include "Projectile.hpp"

Projectile::Projectile(sf::Vector2f position, sf::Vector2f velocity, Projectile::Direction direction, Character *own)
{
    owner = own;
	sf::Vector2f offset;
	sf::VideoMode currentResolution = sf::VideoMode::getDesktopMode();
    initGraphics("Projectile.png");
	sprite.setScale(currentResolution.width / 1920.0f, currentResolution.height / 1080.0f);

	//Set offset of the projectile based on which side of the player it's spawning on
	switch(direction)
	{
	case Projectile::LEFT:
		offset = sf::Vector2f(-getBounds().width, -getBounds().height / 2);
		break;
	case Projectile::RIGHT:
		offset = sf::Vector2f(0, -getBounds().height / 2);
		break;
	case Projectile::UP:
		offset = sf::Vector2f(-getBounds().width / 2, -getBounds().height);
		break;
	case Projectile::DOWN:
		offset = sf::Vector2f(-getBounds().width / 2, 0);
		break;
	default:
		offset = sf::Vector2f(0,0);
	};


	sprite.setPosition(position + offset);
	origin = position;

/*
	//If the player is moving backwards, set the bullet speed to normal.
	//The velocity checks needs to calculated with the actual player and shot speed.
	//velocity.x*=(owner->getStats()["projectileVelocity"]);
    //velocity.y*=(owner->getStats()["projectileVelocity"]);
    if(velocity.x == (config["PROJECTILE_BASE_VELOCITY"] - owner->stats["moveSpeed"]))
	{velocity.x = config["PROJECTILE_BASE_VELOCITY"];}
	else if(velocity.x == -(config["PROJECTILE_BASE_VELOCITY"] - owner->stats["moveSpeed"]))
	{velocity.x = -config["PROJECTILE_BASE_VELOCITY"];}
	else if(velocity.y == (config["PROJECTILE_BASE_VELOCITY"] - owner->stats["moveSpeed"]))
	{velocity.y = config["PROJECTILE_BASE_VELOCITY"];}
	else if(velocity.y == -(config["PROJECTILE_BASE_VELOCITY"] - owner->stats["moveSpeed"]))
	{velocity.y = -config["PROJECTILE_BASE_VELOCITY"];}
*/
	setVelocity(velocity);

	dead = false;
	explosion = true;
}

//The constructor for the death of bullet
Projectile::Projectile(sf::Vector2f position)
{
	sf::Vector2f offset;
	sf::VideoMode currentResolution = sf::VideoMode::getDesktopMode();
    initGraphics("ProjectileDeath.png");
	sprite.setScale(currentResolution.width / 1920.0f, currentResolution.height / 1080.0f);

	//Set offset of the projectile based on which side of the player it's spawning on

	sprite.setPosition(position);
	origin = position;

	setVelocity(sf::Vector2f(0,0));

	dead = false;
	explosion = false;
	frameCount = 0;
}


sf::Vector2f Projectile::getPosition()
{
	return sprite.getPosition();
}

void Projectile::setVelocity(sf::Vector2f _velocity)
{
	velocity = _velocity;
}

void Projectile::update(float elapsedTime)
{
	if (explosion == false)
	{
		frameCount++;
		if (frameCount == 100)
		{dead=true;}
	}
}

