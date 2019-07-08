#include "Character.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Animation.h"

Character::Character(const sf::Vector2f& pos)
	:
	pos(pos)
{
	sprite.setTextureRect(sf::IntRect(8, 8, 30, 32));
	animations[int(AnimationIndex::WalkingUp)]
		= Animation(105, 10, 30, 32, 0, 48);
	animations[int(AnimationIndex::WalkingDown)]
		= Animation(9, 10, 30, 32, 0, 48);
	animations[int(AnimationIndex::WalkingLeft)]
		= Animation(55, 10, 29, 33, 0, 48);
	animations[int(AnimationIndex::WalkingRight)]
		= Animation(154, 10, 29, 33, 0, 48);
}

void Character::draw(sf::RenderTarget& rt) const
{
	rt.draw(sprite);
}

void Character::setDirection(const sf::Vector2f& dir)
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

void Character::update(const float& dt)
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