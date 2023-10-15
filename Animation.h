#pragma once
#include "raylib.h"

class Animation
{
public:
  Animation(Texture2D texture, int numSprites);
  void Update();
  void Draw(Vector2 position);
  int getSpriteWidth();
  int getSpriteHeight();
  float getScale();
  void increaseScale();
  void decreaseScale();

private:
  Texture2D texture;
  int spriteWidth = 32;
  int spriteHeight = 32;
  int numSprites;
  int currentSprite = 0;
  float frameTime = 0.0f;
  float scale = 1.0f;
};
