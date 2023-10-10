#include "Game.h"

void Game::Initialize()
{
	InitWindow(ScreenWidth, ScreenHeight, "RPG");
};

void Game::Update(Animation characterAnimation, AActor character)
{

	while (!WindowShouldClose())
	{
		float deltaTime = GetFrameTime();
		characterAnimation.Update(deltaTime);

		if (IsKeyDown(KEY_RIGHT))
			character.location.x += character.speed * deltaTime;
		if (IsKeyDown(KEY_LEFT))
			character.location.x -= character.speed * deltaTime;
		if (IsKeyDown(KEY_DOWN))
			character.location.y += character.speed * deltaTime;
		if (IsKeyDown(KEY_UP))
			character.location.y -= character.speed * deltaTime;

		BeginDrawing();
		ClearBackground(WHITE);
		characterAnimation.Draw({character.location.x, character.location.y});
		EndDrawing();
	}
	UnloadTexture(characterAnimation.getTexture());
};

void Game::Shutdown()
{
	CloseWindow();
};