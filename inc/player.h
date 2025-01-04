#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"

const float MOVEMENT_SPEED = 10.0f;
const float JUMP_FORCE = 10.0f;
const float GRAVITY = 10.0f;
const float EYE_LVL = 2.0f;

class Player{
    public:
        Player();
        void updatePlayer(Player& player, Camera& camera);
    private:
        Vector3 pos;
        Vector3 vel;
        bool onGround;
};

#endif