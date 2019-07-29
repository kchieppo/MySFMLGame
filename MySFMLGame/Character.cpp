#include "Character.h"

Character::Character()
	:
	vel{ 0.0f, 0.0f }
{
	sprite.setPosition({ 0.0f, 0.0f });
}

Character::Character(const sf::Vector2f& pos)
	:
	vel{ 0.0f, 0.0f }
{
	sprite.setPosition(pos);
}

void Character::draw(sf::RenderTarget& rt) const
{
	rt.draw(sprite);
}
