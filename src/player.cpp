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
        Vector3 oldPos = camera.position;
        Vector3 oldTarget = camera.target;
        Vector3 forward = Vector3Normalize(Vector3Subtract(camera.target, camera.position));
        forward = Vector3Scale(forward, TELEPORT_DISTANCE);
        camera.position = Vector3Add(camera.position, forward);
        camera.target = Vector3Add(camera.target, forward);
        if(camera.position.y > EYE_LVL){
            this->onGround = false;
        }

        updateBox(camera.position);
        if(map.CheckCollision(box)){
            camera.position = oldPos;
            camera.target = oldTarget;
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

    Vector2 delta = GetMouseDelta();
    Vector3 rotation = {
        delta.x * MOUSE_SENSITIVITY,
        delta.y * MOUSE_SENSITIVITY,
        0.0f
    };

    Vector3 oldPos = camera.position;
    Vector3 oldTarget = camera.target;

    Vector3 forward = Vector3Subtract(oldTarget, oldPos);
    forward.y = 0;
    forward = Vector3Normalize(forward);
    Vector3 right = Vector3CrossProduct(forward, {0, 1, 0});

    float forwardMove = ((float)IsKeyDown(KEY_W) - (float)IsKeyDown(KEY_S));
    float rightMove = ((float)IsKeyDown(KEY_D) - (float)IsKeyDown(KEY_A));

    Vector3 movement = {
        (forward.x * forwardMove + right.x * rightMove) * speed,
        this->verticalVel * GetFrameTime(),
        (forward.z * forwardMove + right.z * rightMove) * speed  
    };

    Vector3 xzMovement = {movement.x, 0, movement.z};
    camera.position = Vector3Add(oldPos, xzMovement);
    camera.target = Vector3Add(oldTarget, xzMovement);
    updateBox(camera.position);

    // Wall sliding section 
    if(map.CheckCollision(box)){
        camera.position = oldPos;
        camera.target = oldPos;
        // try just x movement first
        float ogZ = xzMovement.z;
        xzMovement.z = 0;
        camera.position = Vector3Add(oldPos, xzMovement);
        camera.target = Vector3Add(oldTarget, xzMovement);
        updateBox(camera.position);

        if(map.CheckCollision(box)){
            camera.position = oldPos;
            camera.target = oldPos;
            // try just z movement next
            xzMovement.z = ogZ;
            xzMovement.x = 0;
            camera.position = Vector3Add(oldPos, xzMovement);
            camera.target = Vector3Add(oldTarget, xzMovement);
            updateBox(camera.position);

            if(map.CheckCollision(box)){
                camera.position = oldPos;
                camera.target = oldPos;
            }
        }
    }

    camera.position.y += movement.y;
    updateBox(camera.position);

    UpdateCameraPro(&camera, (Vector3){0, 0, 0}, rotation, 0.0f);
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

