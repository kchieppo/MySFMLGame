#include "MainCharacter.h"

MainCharacter::MainCharacter(const sf::Vector2f& pos)
	:
	Character(pos),
	speed(100.0f),
	curAnimation(AnimationIndex::WalkingDown)
{
	sprite.setTextureRect(sf::IntRect(8, 8, 30, 32));
	animations[int(AnimationIndex::WalkingUp)]
		= MainCharacterAnimation("MainCharacterWalkingUp",
			"Sprites/Characters/george.png", 106, 4, 0.2f);
	animations[int(AnimationIndex::WalkingDown)]
		= MainCharacterAnimation("MainCharacterWalkingDown",
			"Sprites/Characters/george.png", 10, 4, 0.2f);
	animations[int(AnimationIndex::WalkingLeft)]
		= MainCharacterAnimation("MainCharacterWalkingLeft",
			"Sprites/Characters/george.png", 56, 4, 0.2f);
	animations[int(AnimationIndex::WalkingRight)]
		= MainCharacterAnimation("MainCharacterWalkingRight",
			"Sprites/Characters/george.png", 155, 4, 0.2f);
}

void MainCharacter::setAnimationIndex(const sf::Vector2f& dir)
{
	vel = dir * speed;
	if (dir.y < 0.0f)
		curAnimation = AnimationIndex::WalkingUp;
	else if (dir.y > 0.0f)
		curAnimation = AnimationIndex::WalkingDown;
	else if (dir.x < 0.0f)
		curAnimation = AnimationIndex::WalkingLeft;
	else if (dir.x > 0.0f)
		curAnimation = AnimationIndex::WalkingRight;
}

void MainCharacter::update(const float& dt)
{
	if (vel.x == 0 && vel.y == 0)
		animations[int(curAnimation)].reset();
	else
	{
		pos += vel * dt;
		animations[int(curAnimation)].update(dt);
		sprite.setPosition(pos);
	}
	animations[int(curAnimation)].applyToSprite(sprite);
}

MainCharacter::MainCharacterAnimation::MainCharacterAnimation(
	const std::string&& name, const std::string&& fileName,
	int xFirstFrame, int numFrames, float timePerFrame)
	:
	Animation(std::move(name), std::move(fileName), numFrames,
		timePerFrame, false)
{
	createFrames(xFirstFrame, yFirstFrame, xOffset, yOffset);
}

void MainCharacter::MainCharacterAnimation::createFrames(
	int xFirstFrame, int yFirstFrame, int xOffset, int yOffset)
{
	for (int i = 0; i < numFrames; i++)
	{
		frames.emplace_back(xFirstFrame + i * xOffset,
			yFirstFrame + i * yOffset, widthFrame, heightFrame);
	}
}
