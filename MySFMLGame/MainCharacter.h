#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Animation.h"

class MainCharacter : public Character
{
public:
	MainCharacter(const sf::Vector2f& pos);
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
	const float speed = 100.0f;
	Animation animations[int(AnimationIndex::Count)];
	AnimationIndex curAnimation;
};