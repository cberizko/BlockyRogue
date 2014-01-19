#ifndef _ENEMY_H
#define _ENEMY_H

class Enemy: public GameObject
{
    public:
        Enemy(sf::Vector2f v2f);
        void update(float elapsed);
	private:
		float health;
};

#endif
