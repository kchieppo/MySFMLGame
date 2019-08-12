#pragma once
#include "AABB.h"
#include "Event.h"
#include <optional>

class TileProperties
{
public:
	TileProperties();
	TileProperties(int& tileNumber);
	const int& getTileNumber() const;
	const std::optional<AABB<sf::Vector2i>>& getAabb() const;
private:
   void setProperties();
private:
	int tileNumber;
	std::optional<AABB<sf::Vector2i>> aabb;
	Event evnt;
};