#include "MainCharacterAnimation.h"

MainCharacterAnimation::MainCharacterAnimation(const std::string&& name,
	const std::string&& fileName, int xFirstFrame, int yFirstFrame,
	int widthFrame, int heightFrame, int xOffset, int yOffset,
	int numFrames, float timePerFrame)
	:
	Animation(std::move(name), std::move(fileName), numFrames,
		timePerFrame)
{
	createFrames(xFirstFrame, yFirstFrame, widthFrame, heightFrame,
		xOffset, yOffset);
}

void MainCharacterAnimation::createFrames(int xFirstFrame, int yFirstFrame,
	int widthFrame, int heightFrame, int xOffset, int yOffset)
{
	for (int i = 0; i < numFrames; i++)
	{
		frames.emplace_back(xFirstFrame + i * xOffset,
			yFirstFrame + i * yOffset, widthFrame, heightFrame);
	}
}
