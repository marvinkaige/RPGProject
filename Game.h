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
	void Update(Player player, EnemyNPC enemy, AllyNPC ally);
	void Shutdown(Player player, EnemyNPC enemy, AllyNPC ally);

private:
	int ScreenWidth = 800;
	int ScreenHeight = 600;
};