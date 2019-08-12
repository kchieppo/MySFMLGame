#include "Animation.h"
#include <iostream>

Animation::Animation(const std::string& name, const std::string& fileName,
   int numFrames, float timePerFrame, bool flipHorizontal)
	:
	name(""),
	numFrames(numFrames),
	curFrameIndex(0),
	totalDeltaT(0.0f),
	timePerFrame(timePerFrame),
	flipHorizontal(flipHorizontal)
{
	frames.reserve(10);
	if (!image.loadFromFile(fileName))
		std::cerr << "Animation can't open " + fileName + ". " << std::endl;
	image.createMaskFromColor(sf::Color::White);
	texture.loadFromImage(image);
}

void Animation::applyToSprite(sf::Sprite& s) const
{
	s.setTexture(texture);
	try {
		s.setTextureRect(frames.at(curFrameIndex));
	}
	catch (const std::out_of_range& oor) {
		std::cerr << "Animation " << name << "tried to set non-existent frame at "
         "index " << curFrameIndex << " to sprite." << std::endl;
		std::cerr << "Out of Range error: " << oor.what() << std::endl;
	}
}

void Animation::reset()
{
	curFrameIndex = 0;
}

void Animation::update(float dt)
{
	totalDeltaT += dt;
	while (totalDeltaT >= timePerFrame)
	{
		totalDeltaT -= timePerFrame;
		advanceFrame();
	}
}
