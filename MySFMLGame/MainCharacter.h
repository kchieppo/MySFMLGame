#pragma once
#include "Character.h"
#include <array>
#include "AABB.h"

/*
The main character controlled by the player.
*/
class MainCharacter : public Character
{
public:
	MainCharacter(const sf::Vector2f& spritePos);
	void draw(sf::RenderTarget& rt) const;
	void setAnimationIndex(const sf::Vector2f& dir) override;
	void setVelocity(const sf::Vector2f& dir) override;
	void update(const float& dt) override;

   // Sets sprite to the exact position passed in.
	void setPosition(const sf::Vector2f& pos);
	void setPositionX(const float& pos);
	void setPositionY(const float& pos);

   // Moves sprite from current position. E.g., if {1, 1} is passed in, the
   // sprite will be moved one pixel to the right and one pixel down.
	void moveDistance(const sf::Vector2f& dist);
	void moveDistanceX(const float& distX);
	void moveDistanceY(const float& distY);

   // Returns true if the sprite's position changed.
	bool getPositionChanged() const;
	void setPositionChanged(const bool& posChanged);

   const sf::Vector2f& getPosition() const;
   const sf::Vector2f& getAabbMin() const;
   const sf::Vector2f& getAabbMax() const;
	const int& getSpriteWidth() const;
	const int& getSpriteHeight() const;
private:

	class MainCharacterAnimation : public Animation
	{
	public:
      /*
      name: name of the animation
      fileName: file containing animation images
      xFirstFrame: x coordinate of the top-left corner of the first image in the
         animation (yFirstFrame is static for MainCharacter)
      numFrames: the number of frames in the animation
      timePerFrame: the time (in seconds) between each frame of the animation
      */
		MainCharacterAnimation(std::string&& name, std::string&& fileName,
			int xFirstFrame, int numFrames, float timePerFrame);

      // Width and height of each image in each MainCharacter animation.
		static constexpr int widthFrame = 29;
		static constexpr int heightFrame = 32;
	protected:
		void createFrames(int xFirstFrame, int yFirstFrame, int xOffset,
         int yOffset) override;
	private:
      // The y coordinate of the first image in all MainCharacter animations is
      // the same, so it's static constexpr.
		static constexpr int yFirstFrame = 11;

      // The number of pixels in between each frame on the sprite sheet. Both
      // are unchanging for MainCharacter, so they are static constexprs.
		static constexpr int xOffset = 0;
		static constexpr int yOffset = 48;
	};

   // The types of MainCharacter animations.
	enum class AnimationIndex
	{
		WalkingUp,
		WalkingDown,
		WalkingLeft,
		WalkingRight,
		Count
	};

	bool positionChanged;

   // The speed at which the character moves across the screen.
	const float speed;

   // Array containing the different types of animations.
	std::array<MainCharacterAnimation, static_cast<int>(AnimationIndex::Count)>
      animations;
	AnimationIndex curAnimation;
	AnimationIndex prevAnimation;

   // Axis-aligned bounding box for collision detection.
	AABB<sf::Vector2f> aabb;

   // Set to true to draw MainCharacter's AABB (for debugging).
	bool drawAabb;
   // Contains a red rectangle representing the AABB
	sf::VertexArray aabbForDrawing;
};