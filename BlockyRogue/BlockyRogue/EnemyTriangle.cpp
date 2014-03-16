#include "EnemyTriangle.hpp"
#include "EnemyManager.hpp"
EnemyTriangle::EnemyTriangle(sf::Vector2f v2f, Player* p, EnemyManager* e, float range, std::list<Projectile*> *proj) : Enemy(v2f, p, e, range)
{
	projectiles = proj;
	coolDownTimer = 0;
    initShape(3, 50, 1, v2f);
	Character::initBoundingBox();
}

void EnemyTriangle::update(float elapsed)
{
	sf::FloatRect initalIntersection;
	for (std::list<Enemy*>::iterator it = manager->getEnemyList()->begin(); it != manager->getEnemyList()->end();++it)
	{
		if((*it)->getBounds().intersects(getBounds(), initalIntersection) && (*it) != this)
		{
			float moveX, moveY;
			if(initalIntersection.left == getBounds().left)
				moveX = initalIntersection.width;
			else
				moveX = -initalIntersection.width;
			if(initalIntersection.top == getBounds().top)
				moveY = initalIntersection.height;
			else
				moveY = -initalIntersection.height;
			boundingBox.move(moveX, moveY);
            shape->update(sf::Vector2f(moveX,moveY));
		}
	}
	if(coolDownTimer > 0)
		coolDownTimer -= elapsed;
	else
	{
		sf::Vector2f direction = player->getPosition() - getPosition();
		float distanceToPlayer = sqrt(direction.x * direction.x + direction.y * direction.y);
		sf::Vector2f normalizedDir = direction / distanceToPlayer;
		if(distanceToPlayer < aggroRange)
		{
			projectiles->push_back(new EnemyProjectile(boundingBox.getPosition() + sf::Vector2f(boundingBox.getSize().x / 2, boundingBox.getSize().y / 2), 
				normalizedDir * (float)config["ENEMY_PROJECTILE_BASE_VELOCITY"]*(float)stats["projectileVelocity"], Projectile::NONE, player, this));
			coolDownTimer = stats["projectileDelay"];
		}
	}
	
}

EnemyTriangle::~EnemyTriangle()
{
}
