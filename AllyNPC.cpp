#include "AllyNPC.h"

AllyNPC::AllyNPC(Texture2D texture, int numSprites) : NPC(texture, numSprites) {
    speed = { 3.1,3.1 };
}

void AllyNPC::CollisionAction() {
    speed.x *= -1;
    speed.y *= -1;
}