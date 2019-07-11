#include "MainCharacter.h"

MainCharacter::MainCharacter(const sf::Vector2f& pos)
	:
	speed(100.0f),
	curAnimation(AnimationIndex::WalkingDown)
{
	sprite.setTextureRect(sf::IntRect(8, 8, 30, 32));
	animations[int(AnimationIndex::WalkingUp)]
		= MainCharacterAnimation("MainCharacterWalkingUp",
			"Sprites/Characters/george.png",
			105, 10, 30, 32, 0, 48, 4, 0.2f);
	animations[int(AnimationIndex::WalkingDown)]
		= MainCharacterAnimation("MainCharacterWalkingDown",
			"Sprites/Characters/george.png",
			9, 10, 30, 32, 0, 48, 4, 0.2f);
	animations[int(AnimationIndex::WalkingLeft)]
		= MainCharacterAnimation("MainCharacterWalkingLeft",
			"Sprites/Characters/george.png",
			55, 10, 29, 33, 0, 48, 4, 0.2f);
	animations[int(AnimationIndex::WalkingRight)]
		= MainCharacterAnimation("MainCharacterWalkingRight",
			"Sprites/Characters/george.png",
			154, 10, 29, 33, 0, 48, 4, 0.2f);
}

void MainCharacter::setDirection(const sf::Vector2f& dir)
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
