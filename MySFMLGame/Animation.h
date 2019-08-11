#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class Animation
{
public:
	Animation() = default;
	Animation(const std::string& name, const std::string& fileName,
		int numFrames, float timePerFrame, bool flipHorizontal);
	virtual void applyToSprite(sf::Sprite& s) const;
	virtual void update(float dt);
	virtual void reset();
protected:
	virtual void createFrames(int xFirstFrame, int yFirstFrame,
		int xOffset, int yOffset) = 0;
private:
	void advanceFrame()
	{
		if (++curFrameIndex >= numFrames)
		{
			curFrameIndex = 0;
		}
	}
protected:
	std::string name;
	sf::Image image;
	sf::Texture texture;
	std::vector<sf::IntRect> frames;
	int numFrames;
	int curFrameIndex;
	float totalDeltaT;
	float timePerFrame;
	bool flipHorizontal;
};