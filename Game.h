#pragma once
#include "raylib.h"
#include "EnemyNPC.h"
#include "AllyNPC.h"
#include "Player.h"

class Game
{
public:
	Game();
	void Initialize();
	void Update();
	void Shutdown();

private:
	int ScreenWidth = 800;
	int ScreenHeight = 600;
};