#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Character
{
public:
	Character();
	Character(const sf::Vector2f& pos);
	virtual void draw(sf::RenderTarget& rt) const;
	virtual void setAnimationIndex(const sf::Vector2f& dir) = 0;
	virtual void update(const float& dt) = 0;
protected:
	sf::Sprite sprite;
	sf::Vector2f vel;
};