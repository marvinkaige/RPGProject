#include "Game.h"

Game::Game()
{
}

void Game::Initialize()
{
	InitWindow(ScreenWidth, ScreenHeight, "RPG");
};

void Game::Update()
{
	SetTargetFPS(60);

	double lastExecutionTime = GetTime();
	double executionInterval = 0.2;

	Texture2D playerTexture = LoadTexture("./Assets/Owlet_Monster_Walk_6.png");
	Player player = Player(playerTexture, 6);

	Texture2D enemyTexture = LoadTexture("./Assets/Pink_Monster_Walk_6.png");
	EnemyNPC enemy = EnemyNPC(enemyTexture, 6);
	enemy.setPosition({ 500, 300 });

	Texture2D allyTexture = LoadTexture("./Assets/Dude_Monster_Walk_6.png");
	AllyNPC ally = AllyNPC(allyTexture, 6);
	ally.setPosition({ 100, 100 });

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

void Game::Shutdown()
{
	CloseWindow();
};