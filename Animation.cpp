#include "Animation.h"

Animation::Animation(Texture2D texture, int numFrames)
{
  this->texture = texture;
  this->numFrames = numFrames;
}

void Animation::Update(float deltaTime)
{
  frameTime += deltaTime;
  if (frameTime >= 1.0f / 10.0f)
  { // 10 FPS animation
    frameTime = 0.0f;
    currentSprite = (currentSprite + 1) % numFrames;
  }
}

void Animation::Draw(Vector2 position)
{
  Rectangle sourceRect = {currentSprite * spriteWidth, 0, spriteWidth, spriteHeight};
  DrawTextureRec(texture, sourceRect, position, WHITE);
}

Texture2D Animation::getTexture()
{
  return texture;
}
