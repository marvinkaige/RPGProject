#include "Animation.h"

Animation::Animation(Texture2D texture, int frameWidth, int frameHeight, int numFrames)
{
  this->texture = texture;
  this->frameWidth = frameWidth;
  this->frameHeight = frameHeight;
  this->numFrames = numFrames;
  this->currentFrame = 0;
  this->frameTime = 0.0f;
}

void Animation::Update(float deltaTime)
{
  frameTime += deltaTime;
  if (frameTime >= 1.0f / 10.0f)
  { // 10 FPS animation
    frameTime = 0.0f;
    currentFrame = (currentFrame + 1) % numFrames;
  }
}

void Animation::Draw(Vector2 position)
{
  Rectangle sourceRect = {currentFrame * frameWidth, 0, frameWidth, frameHeight};
  DrawTextureRec(texture, sourceRect, position, WHITE);
}

Texture2D Animation::getTexture()
{
  return texture;
}
