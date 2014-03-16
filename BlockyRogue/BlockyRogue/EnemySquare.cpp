#include "EnemySquare.hpp"

EnemySquare::EnemySquare(sf::Vector2f v2f, Player* p, float range) : Enemy(v2f, p, range)
{
	knockFrame = 0;
	velocity = new sf::Vector2f();
    std::cout<<"ENEMYSQUARE SPAWNED"<<std::endl;
    initShape(config["ENEMY_SHAPE_STARTING_VERTICES"],
              config["ENEMY_SHAPE_BASE_RADIUS"],
              config["ENEMY_SHAPE_VARIANCE"],
              v2f);
	initBoundingBox();
}

EnemySquare::~EnemySquare()
{
}

void EnemySquare::update(float elapsed)
{
    sf::Vector2f direction = player->getPosition() - getPosition();
	float distanceToPlayer = abs(sqrt(direction.x * direction.x + direction.y * direction.y));

	//If inside aggro range.
	if (distanceToPlayer < aggroRange)
	{
		float magnitude = distanceToPlayer;
		direction.x /= magnitude;
		direction.y /= magnitude;
	
        velocity->x = direction.x * moveSpeed;
        velocity->y = direction.y * moveSpeed;
    shape->update(sf::Vector2f(direction.x * moveSpeed*elapsed, direction.y * moveSpeed * elapsed));
    }
	boundingBox.setPosition(boundingBox.getPosition() + *velocity * elapsed);
}
