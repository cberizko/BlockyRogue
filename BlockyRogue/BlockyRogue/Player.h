#ifndef _PLAYER_H
#define _PLAYER_H
#include "GameObject.h"

class Player: public GameObject
{
    public:
        Player();
        void update(float elapsedTime);
};

#endif
