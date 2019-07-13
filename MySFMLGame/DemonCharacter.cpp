#include "DemonCharacter.h"

DemonCharacter::DemonCharacter(const sf::Vector2f& pos)
	:
	Character(pos),
	speed(50.0f),
	curAnimation(AnimationIndex::StandingStillRight),
	prevAnimation(AnimationIndex::StandingStillRight)
{
	sprite.setTextureRect(sf::IntRect(8, 8, 30, 32));
	sprite.scale({ 2.0f, 2.0f });
	animations[int(AnimationIndex::StandingStillLeft)]
		= DemonCharacterAnimation("DemonCharacterSSL",
			"Sprites/DownloadedTilesets/0x72_DungeonTilesetII_v1.2.png",
			45, 366, -26, 34, 32, 0, 4, 0.2f);
	animations[int(AnimationIndex::StandingStillRight)]
		= DemonCharacterAnimation("DemonCharacterSSR",
			"Sprites/DownloadedTilesets/0x72_DungeonTilesetII_v1.2.png",
			19, 366, 26, 34, 32, 0, 4, 0.2f);
	animations[int(AnimationIndex::WalkingLeft)]
		= DemonCharacterAnimation("DemonCharacterWL",
			"Sprites/DownloadedTilesets/0x72_DungeonTilesetII_v1.2.png",
			172, 366, -26, 34, 32, 0, 4, 0.2f);
	animations[int(AnimationIndex::WalkingRight)]
		= DemonCharacterAnimation("DemonCharacterWR",
			"Sprites/DownloadedTilesets/0x72_DungeonTilesetII_v1.2.png",
			146, 366, 26, 34, 32, 0, 4, 0.2f);
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
