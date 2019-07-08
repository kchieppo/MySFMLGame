#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Character
{
public:
	Character(const sf::Vector2f& pos);
	void draw(sf::RenderTarget& rt) const;
	void setDirection(const sf::Vector2f& dir);
	void update(const float& dt);
private:
	enum class AnimationIndex
	{
		WalkingUp,
		WalkingDown,
		WalkingLeft,
		WalkingRight,
		Count
	};
private:
	static constexpr float speed = 100.0f;
	sf::Vector2f curDir;
	sf::Vector2f pos;
	sf::Vector2f vel = { 0.0f, 0.0f };
	sf::Sprite sprite;
	Animation animations[int(AnimationIndex::Count)];
	AnimationIndex curAnimation = AnimationIndex::WalkingDown;
};