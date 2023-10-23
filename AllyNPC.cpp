#include "AllyNPC.h"

AllyNPC::AllyNPC(Texture2D texture, int numSprites) : NPC(texture, numSprites) {
    speed = { 3.1,3.1 };
}


// Function that reverses the movement in case of collision for AllyNPC
void AllyNPC::CollisionAction() {
    speed.x *= -1;
    speed.y *= -1;
}