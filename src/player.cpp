#include "../inc/player.h"

Player::Player(){
    this->pos = (Vector3){0.0f, EYE_LVL, 0.0f};
    this->vel = (Vector3){0.0f, 0.0f, 0.0f};
    this->onGround = true;
}

void Player::updatePlayer(Player& player, Camera& camera){
    
}