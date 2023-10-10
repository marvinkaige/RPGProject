#include "Animation.h"

Animation::Animation(Texture2D texture, int numSprites)
{
  this->texture = texture;
  this->numSprites = numSprites;
}

void Animation::Update(float deltaTime)
{
  frameTime += deltaTime;
  if (frameTime >= 1.0f / 10.0f)
  { // 10 FPS animation
    frameTime = 0.0f;
    currentSprite = (currentSprite + 1) % numSprites;
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
