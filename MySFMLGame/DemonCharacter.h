#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"
#include <array>
#include "AABB.h"

class DemonCharacter : public Character
{
public:
	DemonCharacter(const sf::Vector2f& pos);
	void setAnimationIndex(const sf::Vector2f& dir) override;
	void update(const float& dt) override;
	void reset(const sf::Vector2f& pos);
private:

	class DemonCharacterAnimation : public Animation
	{
	public:
		DemonCharacterAnimation() = default;
		DemonCharacterAnimation(const std::string& name,
			const std::string& fileName, int xFirstFrame,
			int numFrames, float timePerFrame, bool flipHorizontal);
	protected:
		void createFrames(int xFirstFrame, int yFirstFrame,
			int xOffset, int yOffset) override;
	private:
		static constexpr int yFirstFrame = 366;
		static constexpr int widthFrame = 26;
		static constexpr int heightFrame = 34;
		static constexpr int xOffset = 32;
		static constexpr int yOffset = 0;
	};

	enum class AnimationIndex
	{
		StandingStillLeft,
		StandingStillRight,
		WalkingLeft,
		WalkingRight,
		Count
	};

	static constexpr float scaleFactor = 2.0f;
	const float speed;
	std::array<DemonCharacterAnimation,
		static_cast<int>(AnimationIndex::Count)> animations;
	AnimationIndex curAnimation;
	AnimationIndex prevAnimation;
	AABB<sf::Vector2f> aabb;
};