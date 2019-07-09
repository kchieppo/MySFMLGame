#pragma once
#include "Animation.h"

class MainCharacterAnimation : public Animation
{
public:
	MainCharacterAnimation();
	MainCharacterAnimation(int x, int y, int width, int height,
		int xMult, int yMult);
private:
	static constexpr int nFrames = 4;
	static constexpr float holdTime = 0.2f;
	sf::IntRect frames[nFrames];
};