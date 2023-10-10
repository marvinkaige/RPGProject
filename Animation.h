#pragma once
#include "raylib.h"

class Animation
{
public:
  Animation(Texture2D texture, int frameWidth, int frameHeight, int numFrames);
  void Update(float deltaTime);
  void Draw(Vector2 position);

  Texture2D getTexture();

private:
  Texture2D texture;
  int frameWidth;
  int frameHeight;
  int numFrames;
  int currentFrame;
  float frameTime;
};
