#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Animation
{
public:
	Animation();
	Animation(int x, int y, int width, int height, int xMult, int yMult);
	void applyToSprite(sf::Sprite& s) const;
	void update(float dt);
	void reset();
private:
	void advance()
	{
		if (++iFrame >= nFrames)
		{
			iFrame = 0;
		}
	}
private:
	static constexpr int nFrames = 4;
	static constexpr float holdTime = 0.2f;
	sf::Texture texture;
	sf::IntRect frames[nFrames];
	int iFrame = 0;
	float time = 0.0f;
};