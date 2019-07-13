#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "MainCharacterAnimation.h"
#include <array>

class MainCharacter : public Character
{
public:
	MainCharacter(const sf::Vector2f& pos);
	void setAnimationIndex(const sf::Vector2f& dir);
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
	const float speed;
	std::array<MainCharacterAnimation,
		static_cast<int>(AnimationIndex::Count)> animations;
	AnimationIndex curAnimation;
};