#pragma once
#include "NPC.h"
#include "Player.h"

class EnemyNPC : public NPC {
public:
	EnemyNPC(Texture2D texture, int numSprites);
	void Move(Player* player);
};