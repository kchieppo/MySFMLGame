#pragma once
#include "AABB.h"
#include "Event.h"
#include <optional>

/*
Contains the properties for each tile type, where the type of tile is identified
by a unique tile number. Each tile in a given room gets an associated instance
of TileProperties. The only current property is the AABB, but additional
properties may be added.

This currently only works for GrassRoom. In the future, this may be a base class
for "GrassRoomTileProperties" and other derived forms.
*/
class TileProperties
{
public:
	TileProperties();
	TileProperties(int& tileNumber);
	const int& getTileNumber() const;
	const std::optional<AABB<sf::Vector2i>>& getAabb() const;
private:
   // Sets the properties based on the tile number.
   void setProperties();
private:
   /*
   Uniquely identifies the tile type. Tile number 0 corresponds to the tile
   in the top left corner of the texture. No. 1 is the tile to the right of
   tile 0, etc. E.g., in a 3x3 texture, the tiles are numbered as follows:
   
   |0 1 2|
   |3 4 5|
   |6 7 8|
   
   */ 
	int tileNumber;
	std::optional<AABB<sf::Vector2i>> aabb;
	Event evnt;
};