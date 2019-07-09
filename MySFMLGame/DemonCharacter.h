#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Animation.h"

class DemonCharacter : public Character
{
public:
	DemonCharacter(const sf::Vector2f& pos);
	void setDirection(const sf::Vector2f& dir);
	void update(const float& dt);
private:
	enum class AnimationIndex
	{
		StandingStillLeft,
		StandingStillRight,
		WalkingLeft,
		WalkingRight,
		Count
	};
	const float speed = 100.0f;
	Animation animations[int(AnimationIndex::Count)];
	AnimationIndex curAnimation;
};