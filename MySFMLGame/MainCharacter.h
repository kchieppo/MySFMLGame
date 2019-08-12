#pragma once
#include "Character.h"
#include <array>
#include "AABB.h"

class MainCharacter : public Character
{
public:
	MainCharacter(const sf::Vector2f& spritePos);
	void draw(sf::RenderTarget& rt) const;
	void setAnimationIndex(const sf::Vector2f& dir) override;
	void update(const float& dt) override;
	const sf::Vector2f& getPosition() const;
	const sf::Vector2f& getAabbMin() const;
	const sf::Vector2f& getAabbMax() const;
	void setPosition(const sf::Vector2f& pos);
	void setPositionX(const float& pos);
	void setPositionY(const float& pos);
	void moveDistance(const sf::Vector2f& dist);
	void moveDistanceX(const float& distX);
	void moveDistanceY(const float& distY);
	bool getPositionChanged() const;
	void setPositionChanged(const bool& posChanged);
	const int& getSpriteWidth() const;
	const int& getSpriteHeight() const;
private:

	class MainCharacterAnimation : public Animation
	{
	public:
		MainCharacterAnimation() = default;
		MainCharacterAnimation(const std::string& name,
         const std::string& fileName, int xFirstFrame, int numFrames,
			float timePerFrame);
		static constexpr int widthFrame = 29;
		static constexpr int heightFrame = 32;
	protected:
		void createFrames(int xFirstFrame, int yFirstFrame, int xOffset,
         int yOffset) override;
	private:
		static constexpr int yFirstFrame = 11;
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

	bool positionChanged;
	const float speed;
	std::array<MainCharacterAnimation, static_cast<int>(AnimationIndex::Count)>
      animations;
	AnimationIndex curAnimation;
	AnimationIndex prevAnimation;
	AABB<sf::Vector2f> aabb;

	bool drawAabb;
	sf::VertexArray aabbForDrawing;
};