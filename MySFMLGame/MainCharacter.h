#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"
#include <array>
#include "AABB.h"

class MainCharacter : public Character
{
public:
	MainCharacter(const sf::Vector2f& spritePos);
	void setAnimationIndex(const sf::Vector2f& dir) override;
	void update(const float& dt) override;
private:

	class MainCharacterAnimation : public Animation
	{
	public:
		MainCharacterAnimation() = default;
		MainCharacterAnimation(const std::string&& name,
			const std::string&& fileName, int xFirstFrame,
			int numFrames, float timePerFrame);
	protected:
		void createFrames(int xFirstFrame, int yFirstFrame,
			int xOffset, int yOffset) override;
	private:
		static constexpr int yFirstFrame = 11;
		static constexpr int widthFrame = 29;
		static constexpr int heightFrame = 32;
		static constexpr int xOffset = 0;
		static constexpr int yOffset = 48;
	};

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
	AABB aabb;
};