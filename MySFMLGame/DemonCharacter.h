#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "DemonCharacterAnimation.h"
#include <array>

class DemonCharacter : public Character
{
public:
	DemonCharacter(const sf::Vector2f& pos);
	void setAnimationIndex(const sf::Vector2f& dir);
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
	const float speed;
	std::array<DemonCharacterAnimation,
		static_cast<int>(AnimationIndex::Count)> animations;
	AnimationIndex curAnimation;
	AnimationIndex prevAnimation;
};