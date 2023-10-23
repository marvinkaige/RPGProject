#pragma once
#include "raylib.h"

class AActor
{
public:
	Vector2 getPosition();
	void setPosition(Vector2 newPosition);

private:
	Vector2 position = { 400,300 };
};
