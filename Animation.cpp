#include "Animation.h"

Animation::Animation(Texture2D texture, int numSprites)
{
  this->texture = texture;
  this->numSprites = numSprites;
}


// Update the current sprite
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


// Draw the character with current sprite
void Animation::Draw(Vector2 position)
{
  Rectangle sourceRect = {currentSprite * spriteWidth, 0, spriteWidth, spriteHeight};
  DrawTexturePro(texture, sourceRect, Rectangle{ position.x, position.y, spriteWidth * scale, spriteHeight * scale }, Vector2{}, 0.0f, WHITE);
}


// Different getters and setters for animation variables
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

Texture2D Animation::getTexture() {
    return texture;
};
