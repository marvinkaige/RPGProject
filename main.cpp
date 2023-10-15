#include "Game.h"
#include "raylib.h"
#include "Player.h"
#include "EnemyNPC.h"
#include "AllyNPC.h"

int main()
{
	Game RPGGame;

	RPGGame.Initialize();
	RPGGame.Update();
	RPGGame.Shutdown();

	return 0;
}