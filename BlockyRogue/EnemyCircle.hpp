#ifndef _ENEMYCIRCLE_HPP
#define _ENEMYCIRCLE_HPP

#include "Enemy.hpp"
#include <iostream>
#include <cmath>
#include <SFML/Audio.hpp>
#include "Projectile.hpp"
class EnemyManager;
class EnemyCircle : public Enemy
{
public:
	EnemyCircle(sf::Vector2f v2f, Player* p, EnemyManager* e, float range, std::list<Projectile*> *proj);
	~EnemyCircle();
	void update(float elapsed);
	int knockFrame;
	void hit();
private:
    float coolDownTimer;
    float coolDownTime;
    std::list<Projectile*> *projectiles;
	sf::Sound sound;
};

#endif