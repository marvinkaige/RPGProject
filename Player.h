#pragma once
#include "CharacterBase.h"
#include "NPC.h"
#include "AllyNPC.h"

class Player : public CharacterBase {
public:
	Player(Texture2D texture, int numSprites);
	void Move() override;
	void CheckWall() override;
	bool CheckForCollision(NPC* npc);
	void CollisionWithAlly(AllyNPC* npc);
	void CollisionWithEnemy();
};
