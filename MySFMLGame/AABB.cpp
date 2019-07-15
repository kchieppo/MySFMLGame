#include "AABB.h"

AABB::AABB(const sf::Vector2f& pos,
	const sf::Vector2f& min, const sf::Vector2f& max)
	:
	aabbPos(pos),
	aabbMin(min),
	aabbMax(max),
	aabbDir{ 0.0f, 0.0f }
{
}

void AABB::update(const sf::Vector2f& spriteDir)
{
	aabbPos += spriteDir;
	aabbMin += spriteDir;
	aabbMax += spriteDir;
}

void AABB::update(const sf::Vector2f&& spriteDir)
{
	aabbPos += spriteDir;
	aabbMin += spriteDir;
	aabbMax += spriteDir;
}

const sf::Vector2f& AABB::getPosition() const
{
	return aabbPos;
}

const sf::Vector2f& AABB::getMin() const
{
	return aabbMin;
}

const sf::Vector2f& AABB::getMax() const
{
	return aabbMax;
}
