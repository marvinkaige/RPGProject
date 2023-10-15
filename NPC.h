#pragma once
#include "CharacterBase.h"

class NPC : public CharacterBase {
public:
	NPC(Texture2D texture, int numSprites);
	void Move() override;
	void CheckWall() override;
};