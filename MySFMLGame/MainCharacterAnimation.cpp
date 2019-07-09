#include "MainCharacterAnimation.h"

MainCharacterAnimation::MainCharacterAnimation() = default;

MainCharacterAnimation::MainCharacterAnimation(int x, int y, int width,
	int height, int xMult, int yMult)
{
	texture.loadFromFile("Sprites/Characters/george.png");
	for (int i = 0; i < nFrames; i++)
	{
		frames[i] = { x + i * xMult, y + i * yMult, width, height };
	}
}