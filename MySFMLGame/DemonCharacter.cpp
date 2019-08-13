#include "DemonCharacter.h"
#include <iostream>

DemonCharacter::DemonCharacter(const sf::Vector2f& pos)
	:
	Character(pos),
	speed{ 50.0f },
   animations
   {{
         DemonCharacterAnimation("DemonCharacterSSL",
         "Sprites/DownloadedTilesets/0x72_DungeonTilesetII_v1.2.png", 45, 4,
         0.2f, true),
         DemonCharacterAnimation("DemonCharacterSSR",
         "Sprites/DownloadedTilesets/0x72_DungeonTilesetII_v1.2.png", 19, 4,
         0.2f, false),
         DemonCharacterAnimation("DemonCharacterWL",
         "Sprites/DownloadedTilesets/0x72_DungeonTilesetII_v1.2.png", 172, 4,
         0.2f, true),
         DemonCharacterAnimation("DemonCharacterWR",
         "Sprites/DownloadedTilesets/0x72_DungeonTilesetII_v1.2.png", 146, 4,
         0.2f, false)
   }},
	curAnimation{ AnimationIndex::StandingStillRight },
	prevAnimation{ AnimationIndex::StandingStillRight },
	aabb{ {pos.x - 1.0f * scaleFactor, pos.y + 35.0f * scaleFactor},
		{pos.x + 26.0f * scaleFactor, pos.y + 26.0f * scaleFactor} }
{
	sprite.setTextureRect(sf::IntRect(8, 8, 30, 32));
	sprite.scale({ scaleFactor, scaleFactor });
}

void DemonCharacter::setAnimationIndex(const sf::Vector2f& dir)
{
	vel = dir * speed;
	prevAnimation = curAnimation;
	if (dir.y != 0.0f)
	{
		if (dir.x < 0.0f
			|| prevAnimation == AnimationIndex::StandingStillLeft)
			curAnimation = AnimationIndex::WalkingLeft;
		else if (dir.x > 0.0f
			|| prevAnimation == AnimationIndex::StandingStillRight)
			curAnimation = AnimationIndex::WalkingRight;
	}
	else if (dir.x < 0.0f)
		curAnimation = AnimationIndex::WalkingLeft;
	else if (dir.x > 0.0f)
		curAnimation = AnimationIndex::WalkingRight;
	else
	{
		if (curAnimation == AnimationIndex::WalkingLeft)
			curAnimation = AnimationIndex::StandingStillLeft;
		else if (curAnimation == AnimationIndex::WalkingRight)
			curAnimation = AnimationIndex::StandingStillRight;
	}
}

void DemonCharacter::update(const float& dt)
{
	if (prevAnimation != curAnimation)
	{
		animations[int(prevAnimation)].reset();
		prevAnimation = curAnimation;
	}
	sf::Vector2f spriteDist(vel * dt);
	aabb.update(spriteDist);
	sprite.setPosition(sprite.getPosition() + spriteDist);
	animations[int(curAnimation)].update(dt);
	animations[int(curAnimation)].applyToSprite(sprite);
}

void DemonCharacter::reset(const sf::Vector2f& pos)
{
	sprite.setPosition(pos);
	vel = { 0.0f, 0.0f };
	animations[int(prevAnimation)].reset();
	curAnimation = AnimationIndex::StandingStillRight;
	prevAnimation = curAnimation;
	animations[int(curAnimation)].applyToSprite(sprite);
	aabb.reset();
}

DemonCharacter::DemonCharacterAnimation::DemonCharacterAnimation(
	const std::string& name, const std::string& fileName, int xFirstFrame,
   int numFrames, float timePerFrame, bool flipHorizontal)
	:
	Animation(std::move(name), std::move(fileName), numFrames, timePerFrame,
      flipHorizontal)
{
	createFrames(xFirstFrame, yFirstFrame, xOffset, yOffset);
}

void DemonCharacter::DemonCharacterAnimation::createFrames( int xFirstFrame,
   int yFirstFrame, int xOffset, int yOffset)
{
	int newWidth = 0;
	(flipHorizontal) ? newWidth -= widthFrame : newWidth = widthFrame;

	for (int i = 0; i < numFrames; i++)
	{
		frames.emplace_back(xFirstFrame + i * xOffset, yFirstFrame + i * yOffset,
         newWidth, heightFrame);
	}
}
