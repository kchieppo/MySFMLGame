#include "DemonCharacter.h"

DemonCharacter::DemonCharacter(const sf::Vector2f& pos)
	:
	Character(pos),
	speed(50.0f),
	curAnimation(AnimationIndex::StandingStillRight),
	prevAnimation(AnimationIndex::StandingStillRight)
{
	/*aabb.min = { pos.x, pos.y + 34 };
	aabb.max = { pos.x, pos.y };*/
	sprite.setTextureRect(sf::IntRect(8, 8, 30, 32));
	sprite.scale({ 2.0f, 2.0f });
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
	pos += vel * dt;
	sprite.setPosition(pos);
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
