#pragma once
#include "raylib.h"
#include "AActor.h"
#include "Animation.h"

class Game
{
public:
	void Initialize();
	void Update(Animation characterAnimation, AActor character);
	void Shutdown();

private:
	int ScreenWidth = 800;
	int ScreenHeight = 600;
};