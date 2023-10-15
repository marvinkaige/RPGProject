#include "Game.h"

Game::Game()
{
}

void Game::Initialize()
{
	InitWindow(ScreenWidth, ScreenHeight, "RPG");
	SetTargetFPS(60);
};

void Game::Update(Player player, EnemyNPC enemy, AllyNPC ally)
{
	double lastExecutionTime = GetTime();
	double executionInterval = 0.2;

	while (!WindowShouldClose())
	{
		player.Move();
		enemy.Move(&player);
		ally.Move();

		double currentTime = GetTime();
		double elapsedTime = currentTime - lastExecutionTime;

		if (elapsedTime >= executionInterval) {
			if (player.CheckForCollision(&ally)) {
				player.CollisionWithAlly(&ally);
			}

			if (player.CheckForCollision(&enemy)) {
				player.CollisionWithEnemy();
			}
			lastExecutionTime = currentTime;
		}

		BeginDrawing();
		ClearBackground(WHITE);
		ally.animation.Draw(ally.getPosition());
		player.animation.Draw(player.getPosition());
		enemy.animation.Draw(enemy.getPosition());

		EndDrawing();
	}
};

void Game::Shutdown(Player player, EnemyNPC enemy, AllyNPC ally)
{

		UnloadTexture(player.animation.getTexture());
		UnloadTexture(enemy.animation.getTexture());
		UnloadTexture(ally.animation.getTexture());


	CloseWindow();
};