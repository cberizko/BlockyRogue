#ifndef _ENEMYSQUARE_HPP
#define _ENEMYSQUARE_HPP

#include "Enemy.hpp"
#include <iostream>
#include <cmath>
#include <SFML/Audio.hpp>
class EnemyManager;
class EnemySquare : public Enemy
{
public:
	EnemySquare(sf::Vector2f v2f, Player* p, EnemyManager* e, float range);
	~EnemySquare();
	void update(float elapsed);
	int knockFrame;
	void hit();
private:
	sf::Sound sound;
	sf::SoundBuffer hurtSound;
};

#endif