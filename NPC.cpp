#include "NPC.h"
#include "Player.h"

NPC::NPC(Texture2D texture, int numSprites) : CharacterBase(texture, numSprites) {}


// NPC movement which doesnt have to follow the Player
void NPC::Move() {

    CheckWall();

    setPosition({ getPosition().x - speed.x, getPosition().y});
    setPosition({ getPosition().x, getPosition().y - speed.y});
    
    animation.Update();
}


// Check to see if NPC runs into a wall
void NPC::CheckWall() {
    if ((getPosition().x + animation.getSpriteWidth() >= GetScreenWidth()) || (getPosition().x <= 0)) {
        speed.x *= -1;
    }
    if ((getPosition().y + animation.getSpriteHeight() >= GetScreenHeight()) || (getPosition().y <= 0.0f)) {
        speed.y *= -1;
    }
};

