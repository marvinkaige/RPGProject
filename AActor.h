#pragma once
#include "raylib.h"

class AActor
{
public:
	Vector2 getPosition();
	void setPosition(Vector2 newPosition);
	virtual void Move() = 0;

private:
	Vector2 position = { 400,300 };
};
