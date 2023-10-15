#include "NPC.h"
#include "Player.h"

NPC::NPC(Texture2D texture, int numSprites) : CharacterBase(texture, numSprites) {}

void NPC::Move() {

    CheckWall();

    setPosition({ getPosition().x - speed.x, getPosition().y});
    setPosition({ getPosition().x, getPosition().y - speed.y});
    
    animation.Update();
}

void NPC::CheckWall() {
    if ((getPosition().x + animation.getSpriteWidth() >= GetScreenWidth()) || (getPosition().x <= 0)) {
        speed.x *= -1;
    }
    if ((getPosition().y + animation.getSpriteHeight() >= GetScreenHeight()) || (getPosition().y <= 0.0f)) {
        speed.y *= -1;
    }
};

