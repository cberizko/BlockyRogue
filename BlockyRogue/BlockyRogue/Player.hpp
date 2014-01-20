#ifndef _PLAYER_H
#define _PLAYER_H
#include "GameObject.hpp"

class Player: public GameObject
{
    public:
        Player();
        void update(float elapsedTime);
	private:
		float health;
};

#endif
