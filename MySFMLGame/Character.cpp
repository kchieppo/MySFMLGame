#include "Character.h"

Character::Character()
	:
	spritePos{ 0.0f, 0.0f },
	vel{ 0.0f, 0.0f }
{
}

Character::Character(const sf::Vector2f& spritePos)
	:
	spritePos(spritePos),
	vel{ 0.0f, 0.0f }
{
}

void Character::draw(sf::RenderTarget& rt) const
{
	rt.draw(sprite);
}
