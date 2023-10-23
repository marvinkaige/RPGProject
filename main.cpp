#include "Game.h"
#include "raylib.h"
#include "Player.h"
#include "EnemyNPC.h"
#include "AllyNPC.h"

int main()
{
	Game RPGGame;

	RPGGame.Initialize();

	// Creating all the characters for the game
	Texture2D playerTexture = LoadTexture("./Assets/Owlet_Monster_Walk_6.png");
	Player player = Player(playerTexture, 6);

	Texture2D enemyTexture = LoadTexture("./Assets/Pink_Monster_Walk_6.png");
	EnemyNPC enemy = EnemyNPC(enemyTexture, 6);
	enemy.setPosition({ 500, 300 });

	Texture2D allyTexture = LoadTexture("./Assets/Dude_Monster_Walk_6.png");
	AllyNPC ally = AllyNPC(allyTexture, 6);
	ally.setPosition({ 100, 100 });

	RPGGame.Update(player, enemy, ally);
	RPGGame.Shutdown(player, enemy, ally);

	return 0;
}