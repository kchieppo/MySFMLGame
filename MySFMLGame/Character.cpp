#include "Character.h"

Character::Character()
	:
	pos({ 0.0f, 0.0f }),
	vel({ 0.0f, 0.0f })
{

}

Character::Character(const sf::Vector2f& pos)
	:
	pos(pos),
	vel({ 0.0f, 0.0f })
{
}

void Character::draw(sf::RenderTarget& rt) const
{
	rt.draw(sprite);
}

void Character::setAnimationIndex(const sf::Vector2f& dir)
{
}

void Character::update(const float& dt)
{
}