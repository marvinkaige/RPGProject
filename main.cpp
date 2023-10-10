#include "Game.h"
#include "raylib.h"
#include "Animation.h"
#include "AActor.h"

int main()
{
	Game RPGGame;
	AActor Character;

	RPGGame.Initialize();

	SetTargetFPS(60);
	Texture2D characterTexture = LoadTexture("Assets/Pink_Monster_Walk_6.png");
	Animation characterAnimation(characterTexture, 32, 32, 8); // Adjust frameWidth, frameHeight, and numFrames
	RPGGame.Update(characterAnimation, Character);
	RPGGame.Shutdown();

	return 0;
}