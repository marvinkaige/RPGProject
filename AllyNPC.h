#pragma once
#include "NPC.h"

class AllyNPC : public NPC {
public:
	AllyNPC(Texture2D texture, int numSprites);
	void CollisionAction();
};