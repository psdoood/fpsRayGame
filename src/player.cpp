#include "../inc/player.h"
#include "../inc/raymath.h"

Player::Player(){
    this->onGround = true;
    this->verticalVel = 0.0f;
    float playerWidth = 1.0f;
    float playerHeight = 2.0f;
    this->box = {
        (Vector3){-playerWidth/2, 0, -playerWidth/2},
        (Vector3){playerWidth/2, playerHeight, playerWidth/2}
    };
}

void Player::updatePlayer(Camera& camera, Map& map){
    float speed = MOVEMENT_SPEED;
    if(IsKeyDown(KEY_LEFT_CONTROL)){
        speed *= 2;
    }

    if(IsKeyPressed(KEY_E)){
        Vector3 forward = Vector3Normalize(Vector3Subtract(camera.target, camera.position));
        forward = Vector3Scale(forward, TELEPORT_DISTANCE);
        camera.position = Vector3Add(camera.position, forward);
        camera.target = Vector3Add(camera.target, forward);
        if(camera.position.y > EYE_LVL){
            this->onGround = false;
        }
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

    Vector3 movement{
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
    
    Vector3 oldPos = camera.position;
    UpdateCameraPro(&camera, movement, rotation, 0.0f);
    updateBox(camera.position); 
    
    if(map.CheckCollision(box)){
        Vector3 goodMove = {0, 0, 0};
        camera.position = oldPos;

        Vector3 xMove = {
            movement.x, 0, 0
        };
        UpdateCameraPro(&camera, xMove, rotation, 0.0f);
        updateBox(camera.position); 

        if(!map.CheckCollision(box)){
            goodMove.x += xMove.x;
        }
        camera.position = oldPos;

        Vector3 yMove = {
            0, movement.y, 0
        };
        UpdateCameraPro(&camera, yMove, rotation, 0.0f);
        updateBox(camera.position); 
    
        if(!map.CheckCollision(box)){
            goodMove.y = yMove.y;
        }
        camera.position = oldPos;

        UpdateCameraPro(&camera, goodMove, rotation, 0.0f);
        updateBox(camera.position);

        if(map.CheckCollision(box)){
            camera.position = oldPos;
        }
    }
    oldPos = camera.position;

    camera.position.y += movement.z;
    updateBox(camera.position);
}

void Player::updateBox(Vector3 pos){
    Vector3 size = Vector3Subtract(box.max, box.min);
    box.min = (Vector3){
        pos.x - size.x/2, pos.y - size.y/2, pos.z - size.z/2
    };
    
    box.max = (Vector3){
        pos.x + size.x/2, pos.y + size.y/2, pos.z + size.z/2
    };
}

BoundingBox Player::getBox(){
    return box;
}

