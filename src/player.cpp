#include "../inc/player.h"

Player::Player(){
    this->onGround = true;
    this->verticalVel = 0.0f;
}

void Player::updatePlayer(Camera& camera){
    float speed = MOVEMENT_SPEED;
    if(IsKeyDown(KEY_LEFT_CONTROL)){
        speed *= 2;
    }

    if(this->onGround && IsKeyDown(KEY_SPACE)){
        this->verticalVel = JUMP_FORCE;
        this->onGround = false;
    }

    if(camera.position.y < EYE_LVL){
        this->onGround = true;
        this->verticalVel = 0.0f;
        camera.position.y = EYE_LVL;
    }

    if(!this->onGround){
        this->verticalVel -= GRAVITY * GetFrameTime();
    }

    Vector3 movement = {
        ((float)IsKeyDown(KEY_W) - (float)IsKeyDown(KEY_S)) * speed,
        ((float)IsKeyDown(KEY_D) - (float)IsKeyDown(KEY_A)) * speed,
        this->verticalVel * GetFrameTime()
    };

    Vector2 delta = GetMouseDelta();
    Vector3 rotation = {
        delta.x * MOUSE_SENSITIVITY,
        delta.y * MOUSE_SENSITIVITY,
        0.0f
    };

    UpdateCameraPro(&camera, movement, rotation, 0.0f);
}