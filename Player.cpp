#include "Player.h"

Player::Player(Texture2D texture, int numSprites) : CharacterBase(texture, numSprites) {}


// Function that updates position based on movement with arrow keys input
void Player::Move()
{
    CheckWall();

    if (IsKeyDown(KEY_RIGHT))
        setPosition({ getPosition().x + speed.x, getPosition().y});
    if (IsKeyDown(KEY_LEFT))
        setPosition({ getPosition().x - speed.x, getPosition().y});
    if (IsKeyDown(KEY_DOWN))
        setPosition({ getPosition().x, getPosition().y + speed.y});
    if (IsKeyDown(KEY_UP))
        setPosition({ getPosition().x, getPosition().y - speed.y});

    animation.Update();
}

// Check if Player is moving into a wall
void Player::CheckWall() {
    if (getPosition().x + animation.getSpriteWidth() >= GetScreenWidth()) {
        setPosition({ float(GetScreenWidth()) - animation.getSpriteWidth(), getPosition().y });
    }
    else if (getPosition().x <= 0) {
        setPosition({ 0, getPosition().y });
    }
    else if (getPosition().y + animation.getSpriteHeight() >= GetScreenHeight()) {
        setPosition({getPosition().x, float(GetScreenHeight()) - animation.getSpriteHeight() });
    }
    else if (getPosition().y <= 0.0f) {
        setPosition({ getPosition().x, 0.0f});
    }
}


// Check if Player is colliding with NPC
bool Player::CheckForCollision(NPC* npc) {
    if ((this->getPosition().x <= (npc->getPosition().x + npc->animation.getSpriteWidth()*(npc->animation.getScale())) &&
        (this->getPosition().x + this->animation.getSpriteWidth() * npc->animation.getScale()) >= npc->getPosition().x) &&
        (this->getPosition().y <= (npc->getPosition().y + npc->animation.getSpriteHeight() * npc->animation.getScale()) &&
            (this->getPosition().y + this->animation.getSpriteHeight() * npc->animation.getScale()) >= npc->getPosition().y))
    {
        return true;
    }
    return false;
}

void Player::CollisionWithAlly(AllyNPC* ally) {
    ally->CollisionAction();
    animation.increaseScale();
};


void Player::CollisionWithEnemy() {
    animation.decreaseScale();
};