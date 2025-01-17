#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"
#include "map.h"

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
        // Updates player (camera) position, and handles collison
        void updatePlayer(Camera& camera, Map& map);
        // Updates players BoundingBox as they move
        void updateBox(Vector3 pos);
        BoundingBox getBox();
    private:
        bool onGround;
        float verticalVel;
        BoundingBox box;
};

#endif
