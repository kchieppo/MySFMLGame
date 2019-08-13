#include "TileProperties.h"
#include <functional>

TileProperties::TileProperties()
   :
   number{ 0 },
   location{ 0, 0 },
	aabb{ std::nullopt }
{
}

TileProperties::TileProperties(const int& tNumber,
   const sf::Vector2i& tLocation)
	:
	number{ tNumber },
   location{ tLocation },
	aabb{ std::nullopt }
{
	setProperties();
}

const int& TileProperties::getNumber() const
{
	return number;
}

const sf::Vector2i& TileProperties::getLocation() const
{
   return location;
}

const std::optional<AABB<sf::Vector2i>>& TileProperties::getAabb() const
{
	return aabb;
}

void TileProperties::setProperties()
{
	switch (number)
	{
	case 0:
		break;
	case 1:
		break;
	case 207:
		sf::Vector2i&& min{ 0, 13 };
		sf::Vector2i&& max{ 14, 1 };
      aabb = std::optional<AABB<sf::Vector2i>>{{ min, max }};
		break;
	}
}
