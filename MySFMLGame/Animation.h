#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Animation
{
public:
	Animation();
	Animation(int x, int y, int width, int height, int xMult, int yMult);
	virtual void applyToSprite(sf::Sprite& s) const;
	virtual void update(float dt);
	virtual void reset();
private:
	void advance()
	{
		if (++iFrame >= nFrames)
		{
			iFrame = 0;
		}
	}
protected:
	sf::Texture texture;
	int iFrame = 0;
	float time = 0.0f;
private:
	static constexpr int nFrames = 4;
	static constexpr float holdTime = 0.2f;
	sf::IntRect frames[nFrames];
};