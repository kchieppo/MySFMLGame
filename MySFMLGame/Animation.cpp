#include "Animation.h"

Animation::Animation() = default;

Animation::Animation(int x, int y, int width, int height, int xMult, int yMult)
{
	texture.loadFromFile("Sprites/Characters/george.png");
	for (int i = 0; i < nFrames; i++)
	{
		frames[i] = { x + i * xMult, y + i * yMult, width, height };
	}
}

void Animation::applyToSprite(sf::Sprite& s) const
{
	s.setTexture(texture);
	s.setTextureRect(frames[iFrame]);
}

void Animation::reset()
{
	iFrame = 0;
}

void Animation::update(float dt)
{
	time += dt;
	while (time >= holdTime)
	{
		time -= holdTime;
		advance();
	}
}