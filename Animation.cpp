#include "Animation.h"

Animation::Animation(Texture2D texture, int numSprites)
{
  this->texture = texture;
  this->numSprites = numSprites;
}

void Animation::Update()
{
  float deltaTime = GetFrameTime();
  frameTime += deltaTime;
  if (frameTime >= 1.0f / 10.0f)
  {
    frameTime = 0.0f;
    currentSprite++;
    if (currentSprite >= numSprites)
    {
      currentSprite = 0;
    }
  }
}

void Animation::Draw(Vector2 position)
{
  Rectangle sourceRect = {currentSprite * spriteWidth, 0, spriteWidth, spriteHeight};
  DrawTexturePro(texture, sourceRect, Rectangle{ position.x, position.y, spriteWidth * scale, spriteHeight * scale }, Vector2{}, 0.0f, WHITE);
}

float Animation::getScale() {
    return scale;
}

int Animation::getSpriteWidth() {
    return spriteWidth;
};

int Animation::getSpriteHeight() {
    return spriteHeight;
};

void Animation::increaseScale() {
    scale *= 1.05;
}

void Animation::decreaseScale() {
    scale *= 0.98;
}