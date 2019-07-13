#pragma once
#include "Animation.h"

class DemonCharacterAnimation : public Animation
{
public:
	DemonCharacterAnimation() = default;
	DemonCharacterAnimation(const std::string&& name,
		const std::string&& fileName, int xFirstFrame,
		int yFirstFrame, int widthFrame, int heightFrame,
		int xOffset, int yOffset, int numFrames, float timePerFrame);
protected:
	void createFrames(int xFirstFrame, int yFirstFrame,
		int widthFrame, int heightFrame, int xOffset,
		int yOffset) override;
};