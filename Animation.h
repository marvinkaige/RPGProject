#pragma once
#include "raylib.h"

class Animation
{
public:
  Animation(Texture2D texture, int numSprites);
  void Update(float deltaTime);
  void Draw(Vector2 position);
  Texture2D getTexture();

private:
  Texture2D texture;
  int spriteWidth = 32;
  int spriteHeight = 32;
  int numSprites;
  int currentSprite = 0;
  float frameTime = 0.0f;
};
