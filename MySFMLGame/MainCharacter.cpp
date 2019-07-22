#include "MainCharacter.h"

MainCharacter::MainCharacter(const sf::Vector2f& spritePos)
	:
	Character(spritePos),
	speed(100.0f),
	curAnimation(AnimationIndex::WalkingDown),
	aabb{ {spritePos.x + 3.0f, spritePos.y + 32.0f},
		{spritePos.x + 25.0f, spritePos.y + 23.0f} }
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
	}
	animations[int(curAnimation)].applyToSprite(sprite);
}

const sf::Vector2f& MainCharacter::getPosition() const
{
	return spritePos;
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
