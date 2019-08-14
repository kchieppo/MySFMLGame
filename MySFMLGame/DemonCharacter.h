#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"
#include <array>
#include "AABB.h"

/*
The demon NPC.
*/
class DemonCharacter : public Character
{
public:
   DemonCharacter(const sf::Vector2f& pos);
   void setAnimationIndex(const sf::Vector2f& dir) override;
   void update(const float& dt) override;

   // Resets the character to its starting position. Useful when resetting the
   // containing room to its original configuration.
   // TODO: No parameters. Resets to private const position.
   void reset(const sf::Vector2f& pos);
private:
   class DemonCharacterAnimation : public Animation
   {
   public:
      /*
      name: name of the animation
      fileName: file containing animation images
      xFirstFrame: x coordinate of the top-left corner of the first image in the
         animation (yFirstFrame is static for MainCharacter)
      numFrames: the number of frames in the animation
      timePerFrame: the time (in seconds) between each frame of the animation
      flipHorizontal: Flips the images used. Useful, for example, if a walking
         right animation is needed, but one only has images for a walking left
         animation.
      */
      DemonCharacterAnimation(const std::string& name,
         const std::string& fileName, int xFirstFrame, int numFrames,
         float timePerFrame, bool flipHorizontal);
   protected:
      /*
      Makes the frames for the animation. Specifically, the frames variable is
      populated with IntRects whose dimensions enclose the images in the texture
      that are needed for the animation.

      Some of the parameters may be constants in derived Character classes, but
      decided that this general form be derived anyway to remain open to
      sprite sheets that may be organized differently.

      x/yFirstFrame: x/y coordinate of the top-left corner of the first image of
         the animation.
      x/yOffset: The number of pixels between each frame of the animation in the
         x/y direction.
      */
      void createFrames(int xFirstFrame, int yFirstFrame, int xOffset,
         int yOffset) override;
   private:
      static constexpr int yFirstFrame = 366;
      static constexpr int widthFrame = 26;
      static constexpr int heightFrame = 34;
      static constexpr int xOffset = 32;
      static constexpr int yOffset = 0;
   };

   // The types of DemonCharacter animations.
   enum class AnimationIndex
   {
      StandingStillLeft,
      StandingStillRight,
      WalkingLeft,
      WalkingRight,
      Count
   };

   // Scales the size of the images in the animations.
   static constexpr float scaleFactor = 2.0f;
   // The speed at which the character moves across the screen.
   const float speed;
   // Array containing the different types of animations.
   std::array<DemonCharacterAnimation, static_cast<int>(AnimationIndex::Count)>
      animations;
   AnimationIndex curAnimation;
   AnimationIndex prevAnimation;
   // Axis-aligned bounding box for collision detection.
   AABB<sf::Vector2f> aabb;
};