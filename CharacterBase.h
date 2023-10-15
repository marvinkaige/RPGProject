#pragma once
#include "AActor.h"
#include "Animation.h"

class CharacterBase : public AActor
{
public:
	CharacterBase(Texture2D texture, int numSprites);
	Animation animation;
	virtual void Move() = 0;
	virtual void CheckWall() = 0;

protected:
	Vector2 speed = {2,2};
};