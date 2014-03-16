#include "EnemyProjectile.hpp"
EnemyProjectile::EnemyProjectile(sf::Vector2f position, 
								   sf::Vector2f velocity, Projectile::Direction direction, 
								   Player *p, Character *own) : Projectile(position, velocity, direction, own)
{
	player = p;
	if(!buffer.loadFromFile(getResourcePath("Assets/Sounds/")+"Enemy shoot.wav"))
	{
        std::cout << "ERROR unable to load sound Enemy shoot.wav in EnemyProjectile.cpp."<< std::endl;
    }
	fire.setBuffer(buffer);
	fire.play();
    range = own->stats["projectileRange"];
    damage = own->stats["projectileDamage"];
}

EnemyProjectile::~EnemyProjectile()
{
}

void EnemyProjectile::update(float elapsed)
{
	sprite.move(velocity.x * elapsed, velocity.y * elapsed);
	sf::Vector2f moved = sprite.getPosition() - origin;
	float distance = sqrtf(moved.x * moved.x + moved.y * moved.y);
	if(distance >= range)
		dead = true;
	if(getBounds().intersects(player->getBounds()))
	{
		float magnitude = sqrtf(velocity.x * velocity.x + velocity.y * velocity.y);
		player->hit(velocity / magnitude, (float)(damage));
		dead = true;
	}
}