#include "TileProperties.h"
#include <functional>

TileProperties::TileProperties()
	:
	tileNumber{ 0 },
	aabb{ std::nullopt }
{

}

TileProperties::TileProperties(int& tileNumber)
	:
	tileNumber{ tileNumber },
	aabb{ std::nullopt }
{
	setProperties();
}

const int& TileProperties::getTileNumber() const
{
	return tileNumber;
}

const std::optional<AABB<sf::Vector2i>>& TileProperties::getAabb() const
{
	return aabb;
}

void TileProperties::setProperties()
{
	switch (tileNumber)
	{
	case 0:
		break;
	case 1:
		break;
	case 207:
		sf::Vector2i&& min{ 0, 13 };
		sf::Vector2i&& max{ 14, 1 };
		aabb = AABB<sf::Vector2i>(min, max);
		break;
	}
}
