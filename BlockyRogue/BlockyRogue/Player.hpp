#ifndef _PLAYER_H
#define _PLAYER_H
#include "GameObject.hpp"

class Player: public GameObject
{
    public:
        Player();
        ~Player();
        void update(float elapsedTime);
	private:
		double health;
        double moveSpeed;
};

#endif
