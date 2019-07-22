#include "DemonCharacter.h"
#include <iostream>

DemonCharacter::DemonCharacter(const sf::Vector2f& spritePos)
	:
	Character(spritePos),
	speed(50.0f),
	curAnimation(AnimationIndex::StandingStillRight),
	prevAnimation(AnimationIndex::StandingStillRight),
	aabb{ {spritePos.x - 1.0f * scaleFactor, spritePos.y + 35.0f * scaleFactor},
		{spritePos.x + 26.0f * scaleFactor, spritePos.y + 26.0f * scaleFactor} }
{
	sprite.setTextureRect(sf::IntRect(8, 8, 30, 32));
	sprite.scale({ scaleFactor, scaleFactor });
	animations[int(AnimationIndex::StandingStillLeft)]
		= DemonCharacterAnimation("DemonCharacterSSL",
			"Sprites/DownloadedTilesets/0x72_DungeonTilesetII_v1.2.png",
			45, 4, 0.2f, true);
	animations[int(AnimationIndex::StandingStillRight)]
		= DemonCharacterAnimation("DemonCharacterSSR",
			"Sprites/DownloadedTilesets/0x72_DungeonTilesetII_v1.2.png",
			19, 4, 0.2f, false);
	animations[int(AnimationIndex::WalkingLeft)]
		= DemonCharacterAnimation("DemonCharacterWL",
			"Sprites/DownloadedTilesets/0x72_DungeonTilesetII_v1.2.png",
			172, 4, 0.2f, true);
	animations[int(AnimationIndex::WalkingRight)]
		= DemonCharacterAnimation("DemonCharacterWR",
			"Sprites/DownloadedTilesets/0x72_DungeonTilesetII_v1.2.png",
			146, 4, 0.2f, false);
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
	sf::Vector2f spriteDir(vel * dt);
	aabb.update(spriteDir);

	// test collision
	float diffx1, diffx2, diffy1, diffy2;
	int xp = 200, yp = 200;
	diffx1 = xp - aabb.getMin().x;
	diffx2 = aabb.getMax().x - xp;
	diffy1 = yp - aabb.getMax().y;
	diffy2 = aabb.getMin().y - yp;

	// if collision with aabb, backtrack sprite's aabb position
	if (diffx1 >= 0 && diffx2 >= 0 && diffy1 >= 0 && diffy2 >= 0)
		aabb.update(-spriteDir);
	else // leave new aabb position alone and adjust sprite pos
		spritePos += spriteDir;

	sprite.setPosition(spritePos);
	animations[int(curAnimation)].update(dt);
	animations[int(curAnimation)].applyToSprite(sprite);
}

DemonCharacter::DemonCharacterAnimation::DemonCharacterAnimation(
	const std::string&& name, const std::string&& fileName,
	int xFirstFrame, int numFrames, float timePerFrame,
	bool flipHorizontal)
	:
	Animation(std::move(name), std::move(fileName), numFrames,
		timePerFrame, flipHorizontal)
{
	createFrames(xFirstFrame, yFirstFrame, xOffset, yOffset);
}

void DemonCharacter::DemonCharacterAnimation::createFrames(
	int xFirstFrame, int yFirstFrame, int xOffset, int yOffset)
{
	int newWidth = 0;
	(flipHorizontal) ? newWidth -= widthFrame : newWidth = widthFrame;

	for (int i = 0; i < numFrames; i++)
	{
		frames.emplace_back(xFirstFrame + i * xOffset,
			yFirstFrame + i * yOffset, newWidth, heightFrame);
	}
}
