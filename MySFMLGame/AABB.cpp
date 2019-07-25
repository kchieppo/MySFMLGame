#include "AABB.h"

AABB::AABB(const sf::Vector2f& min, const sf::Vector2f& max)
	:
	aabbMinStart{ min },
	aabbMaxStart{ max },
	aabbMin{ min },
	aabbMax{ max }
{
}

void AABB::update(const sf::Vector2f& spriteDir)
{
	aabbMin += spriteDir;
	aabbMax += spriteDir;
}

void AABB::update(const sf::Vector2f&& spriteDir)
{
	aabbMin += spriteDir;
	aabbMax += spriteDir;
}

const sf::Vector2f& AABB::getMin() const
{
	return aabbMin;
}

const sf::Vector2f& AABB::getMax() const
{
	return aabbMax;
}

void AABB::reset()
{
	aabbMin = aabbMinStart;
	aabbMax = aabbMaxStart;
}
