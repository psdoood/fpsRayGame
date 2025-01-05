#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"

const float MOVEMENT_SPEED = 0.1f;
const float JUMP_FORCE = 10.0f;
const float GRAVITY = 15.0f;
const float EYE_LVL = 2.0f;
const float SPRINT_MULT = 2.0f;
const float MOUSE_SENSITIVITY = 0.1;
const float TELEPORT_DISTANCE = 10.0f;

class Player{
    public:
        Player();
        void updatePlayer(Camera& camera);
    private:
        bool onGround;
        float verticalVel;
};

#endif