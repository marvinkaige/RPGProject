#include "EnemyNPC.h"

EnemyNPC::EnemyNPC(Texture2D texture, int numSprites) : NPC(texture, numSprites) {}


// EnemyNPC move function to move towards the Player
void EnemyNPC::Move(Player* player) {

    CheckWall();

    if (player->getPosition().x > getPosition().x) {
        setPosition({ getPosition().x + 0.7f, getPosition().y});
    }
    else {
        setPosition({ getPosition().x - 0.7f, getPosition().y });
    }

    if (player->getPosition().y > getPosition().y) {
        setPosition({ getPosition().x, getPosition().y + 0.7f });
    }
    else {
        setPosition({ getPosition().x, getPosition().y - 0.7f });
    }

    animation.Update();
}

