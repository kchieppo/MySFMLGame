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
      Populates
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
   std::array<DemonCharacterAnimation, static_cast<int>(AnimationIndex::Count)>
      animations;
   AnimationIndex curAnimation;
   AnimationIndex prevAnimation;
   AABB<sf::Vector2f> aabb;
};