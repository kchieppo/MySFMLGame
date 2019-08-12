#include "GrassRoom.h"

GrassRoom::GrassRoom()
	:
	Room("Sprites/Environment/gfx/Overworld.png", "GrassRoom", 16, 16, true),
	roomMatrix{ {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 283, 283, 283, 283, 283, 283, 283, 283, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 283, 283, 283, 283, 283, 283, 283, 283, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 283, 283, 283, 283, 283, 283, 283, 283, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 283, 283, 283, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 323, 323, 323, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 364, 365, 365, 365, 365, 365, 365, 365, 365, 365, 365, 366, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 404, 405, 405, 405, 405, 405, 405, 405, 405, 405, 405, 406, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 444, 445, 445, 445, 445, 445, 445, 445, 445, 445, 445, 446, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 484, 485, 485, 485, 485, 485, 485, 485, 485, 485, 485, 486, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 524, 525, 525, 525, 525, 525, 525, 525, 525, 525, 525, 526, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 524, 525, 525, 525, 525, 525, 525, 525, 525, 525, 525, 526, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 524, 525, 525, 525, 525, 525, 525, 525, 525, 525, 525, 526, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 524, 525, 525, 525, 525, 525, 525, 525, 525, 525, 525, 526, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 524, 525, 525, 525, 525, 525, 525, 525, 525, 525, 525, 526, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 524, 525, 525, 525, 525, 525, 525, 525, 525, 525, 525, 526, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 207, 207, 207, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 207, 0, 0, 0, 207, 207, 207, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 207, 207, 207, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 207, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 207, 0, 0, 0, 207, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 207, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 207, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 207, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	} },
	demon{ {demonStartPosX, demonStartPosY} },
	tilePositionsPrepared{ false },
	mainCharAabbMinLast{ 0.0f, 0.0f }
{
	initTilePropertiesMat();
}

void GrassRoom::load(MainCharacter* mcP)
{
	Room::load(mcP);

	mainCharAabbMinLast = mcPointer->getAabbMin();
	// load the tileset texture
	if (!texture.loadFromFile(fileName))
	{
		std::cerr << "Problem loading " << fileName << " to texture in "
			<< roomName << " load." << std::endl;
		return;
	}

	// resize the vertex array to fit the level size
	vertexArray.setPrimitiveType(sf::Quads);
	vertexArray.resize(roomDimCol * roomDimRow * 4);

	/*vertexArrayLayerTwo.setPrimitiveType(sf::Quads);
	vertexArrayLayerTwo.resize(roomDimCol * roomDimRow * 4);*/

	// populate the vertex array, with one quad per tile
	for (int j = 0; j < roomDimRow; j++)
		for (int i = 0; i < roomDimCol; i++)
		{
			// get the current tile number
			const unsigned int& tileNumber = roomMatrix[j][i];

			// find its position in the tileset texture
			unsigned int tu = tileNumber % (texture.getSize().x / tileWidth);
			unsigned int tv = tileNumber / (texture.getSize().x / tileWidth);

			// get a pointer to the current tile's quad
			sf::Vertex* quad = &vertexArray[(i + j * roomDimCol) * 4];

			// load tile positions properly if starting room
			if (firstRoom)
			{
				// define its 4 corners
				quad[0].position = sf::Vector2f
            (
               static_cast<float>(i * tileWidth),
					static_cast<float>(j * tileHeight)
            );
				quad[1].position = sf::Vector2f
            (
               static_cast<float>((i + 1) * tileWidth),
					static_cast<float>(j * tileHeight)
            );
				quad[2].position = sf::Vector2f
            (
               static_cast<float>((i + 1) * tileWidth),
					static_cast<float>((j + 1) * tileHeight)
            );
				quad[3].position = sf::Vector2f
            (
               static_cast<float>(i * tileWidth),
					static_cast<float>((j + 1) * tileHeight)
            );
			}
			else // make sure positions are off-screen
			{
				quad[0].position
               = sf::Vector2f(static_cast<float>(-tileWidth), 0.0f);
				quad[1].position
               = sf::Vector2f(static_cast<float>(-tileWidth), 0.0f);
				quad[2].position
               = sf::Vector2f(static_cast<float>(-tileWidth), 0.0f);
				quad[3].position
               = sf::Vector2f(static_cast<float>(-tileWidth), 0.0f);
			}

			// define its 4 texture coordinates
			quad[0].texCoords = sf::Vector2f
         (
            static_cast<float>(tu * tileWidth),
				static_cast<float>(tv * tileHeight)
         );
			quad[1].texCoords = sf::Vector2f
         (
            static_cast<float>((tu + 1) * tileWidth),
				static_cast<float>(tv * tileHeight)
         );
			quad[2].texCoords = sf::Vector2f
         (
            static_cast<float>((tu + 1) * tileWidth),
				static_cast<float>((tv + 1) * tileHeight)
         );
			quad[3].texCoords = sf::Vector2f
         (
            static_cast<float>(tu * tileWidth),
				static_cast<float>((tv + 1) * tileHeight)
         );
		}
	roomLoaded = true;
}

void GrassRoom::findTilesStandingOver()
{
	if (!mcPointer->getPositionChanged())
		return;
	mcPointer->setPositionChanged(false);

	float diffX = mcPointer->getAabbMin().x - mainCharAabbMinLast.x;
	float diffY = mcPointer->getAabbMin().y - mainCharAabbMinLast.y;
	mainCharAabbMinLast = mcPointer->getAabbMin();

	Direction dirX = Direction::None, dirY = Direction::None;

	if (diffX > 0) dirX = Direction::Right;
	else if (diffX < 0) dirX = Direction::Left;
	if (diffY > 0) dirY = Direction::Down;
	else if (diffY < 0) dirY = Direction::Up;

	sf::Vector2i tileIndexTopLeft
	{
		static_cast<int>(mcPointer->getAabbMin().x) / tileWidth,
		static_cast<int>(mcPointer->getAabbMax().y) / tileHeight
	};
	sf::Vector2i tileIndexTopRight
	{
		static_cast<int>(mcPointer->getAabbMax().x) / tileWidth,
		static_cast<int>(mcPointer->getAabbMax().y) / tileHeight
	};
	sf::Vector2i tileIndexBottomLeft
	{
		static_cast<int>(mcPointer->getAabbMin().x) / tileWidth,
		static_cast<int>(mcPointer->getAabbMin().y) / tileHeight
	};
	sf::Vector2i tileIndexBottomRight
	{
		static_cast<int>(mcPointer->getAabbMax().x) / tileWidth,
		static_cast<int>(mcPointer->getAabbMin().y) / tileHeight
	};

	sf::Vector2i tileLocation;
	if (dirY == Direction::Up)
	{
		int col = tileIndexTopLeft.x;
		while (col <= tileIndexTopRight.x)
		{
			tileLocation = { col, tileIndexTopLeft.y };
			const TileProperties& tileProperties
				= tilePropertiesMat[tileIndexTopLeft.y][col];
			if (const auto& aabb = tileProperties.getAabb())
				if (checkForCollision(dirX, dirY, tileLocation, aabb.value()))
					return;
			col++;
		}

		if (tileIndexTopLeft != tileIndexBottomLeft)
		{
			if (dirX == Direction::Left)
			{
				int row = tileIndexTopLeft.y + 1;
				while (row <= tileIndexBottomLeft.y)
				{
					tileLocation = { tileIndexTopLeft.x, row };
					const TileProperties& tileProperties
						= tilePropertiesMat[row][tileIndexTopLeft.x];
					if (const auto& aabb = tileProperties.getAabb())
						if (checkForCollision(dirX, dirY, tileLocation, aabb.value()))
							return;
					row++;
				}
			}
			else if (dirX == Direction::Right)
			{
				int row = tileIndexTopRight.y + 1;
				while (row <= tileIndexBottomRight.y)
				{
					tileLocation = { tileIndexTopRight.x, row };
					const TileProperties& tileProperties
						= tilePropertiesMat[row][tileIndexTopRight.x];
					if (const auto& aabb = tileProperties.getAabb())
						if (checkForCollision(dirX, dirY, tileLocation, aabb.value()))
							return;
					row++;
				}
			}
		}
	}
	else if (dirY == Direction::Down)
	{
		int col = tileIndexBottomLeft.x;
		while (col <= tileIndexBottomRight.x)
		{
			tileLocation = { col, tileIndexBottomLeft.y };
			const TileProperties& tileProperties
				= tilePropertiesMat[tileIndexBottomLeft.y][col];
			if (const auto& aabb = tileProperties.getAabb())
				if (checkForCollision(dirX, dirY, tileLocation, aabb.value()))
					return;
			col++;
		}

		if (dirX == Direction::Left)
		{
			int row = tileIndexBottomLeft.y - 1;
			while (row >= tileIndexTopLeft.y)
			{
				tileLocation = { tileIndexBottomLeft.x, row };
				const TileProperties& tileProperties
					= tilePropertiesMat[row][tileIndexBottomLeft.x];
				if (const auto& aabb = tileProperties.getAabb())
					if (checkForCollision(dirX, dirY, tileLocation, aabb.value()))
						return;
				row--;
			}
		}
		else if (dirX == Direction::Right)
		{
			int row = tileIndexBottomRight.y - 1;
			while (row >= tileIndexTopRight.y)
			{
				tileLocation = { tileIndexBottomRight.x, row };
				const TileProperties& tileProperties
					= tilePropertiesMat[row][tileIndexBottomRight.x];
				if (const auto& aabb = tileProperties.getAabb())
					if (checkForCollision(dirX, dirY, tileLocation, aabb.value()))
						return;
				row--;
			}
		}
	}
	else
	{
		if (dirX == Direction::Left)
		{
			int row = tileIndexTopLeft.y;
			while (row <= tileIndexBottomLeft.y)
			{
				tileLocation = { tileIndexTopLeft.x, row };
				const TileProperties& tileProperties
					= tilePropertiesMat[row][tileIndexTopLeft.x];
				if (const auto& aabb = tileProperties.getAabb())
					if (checkForCollision(dirX, dirY, tileLocation, aabb.value()))
						return;
				row++;
			}
		}
		else if (dirX == Direction::Right)
		{
			int row = tileIndexTopRight.y;
			while (row <= tileIndexBottomRight.y)
			{
				tileLocation = { tileIndexTopRight.x, row };
				const TileProperties& tileProperties
					= tilePropertiesMat[row][tileIndexTopRight.x];
				if (const auto& aabb = tileProperties.getAabb())
					if (checkForCollision(dirX, dirY, tileLocation, aabb.value()))
						return;
				row++;
			}
		}
	}
}

void GrassRoom::update(const float& dt)
{
	if (!translating)
	{
		demon.update(dt);
	}
}

void GrassRoom::reset()
{
	demon.reset({ demonStartPosX, demonStartPosY });
}

void GrassRoom::translateIn(Direction& dir)
{
	if (!tilePositionsPrepared)
		prepareTilePositions(dir);

	sf::Vector2f dirVec = getUnitVector(dir);
	sf::Vertex* quad;
	switch (dir)
	{
	case Direction::Up:
		if (vertexArray[0].position.y
         + dirVec.y * static_cast<float>(transMag) == 0)
		{
			dir = Direction::None;
			translating = false;
			tilePositionsPrepared = false;
		}

		for (int j = 0; j < roomDimRow; j++)
			for (int i = 0; i < roomDimCol; i++)
			{
				quad = &vertexArray[(i + j * roomDimCol) * 4];

				quad[0].position.y += dirVec.y * static_cast<float>(transMag);
				quad[1].position.y += dirVec.y * static_cast<float>(transMag);
				quad[2].position.y += dirVec.y * static_cast<float>(transMag);
				quad[3].position.y += dirVec.y * static_cast<float>(transMag);

				if (roomDimRow * tileHeight - quad[0].position.y <= tileHeight
					&& i == roomDimCol - 1)
					return;
			}
		break;
	case Direction::Down:
		if (vertexArray[0].position.y
         + dirVec.y * static_cast<float>(transMag) == 0)
		{
			dir = Direction::None;
			translating = false;
			tilePositionsPrepared = false;
		}

		for (int j = roomDimRow - 1; j >= 0; j--)
			for (int i = 0; i < roomDimCol; i++)
			{
				quad = &vertexArray[(i + j * roomDimCol) * 4];

				quad[0].position.y += dirVec.y * static_cast<float>(transMag);
				quad[1].position.y += dirVec.y * static_cast<float>(transMag);
				quad[2].position.y += dirVec.y * static_cast<float>(transMag);
				quad[3].position.y += dirVec.y * static_cast<float>(transMag);

				if (quad[2].position.y <= tileHeight && i == roomDimCol - 1)
					return;
			}
		break;
	case Direction::Left:
		if (vertexArray[0].position.x
         + dirVec.x * static_cast<float>(transMag) == 0)
		{
			dir = Direction::None;
			translating = false;
			tilePositionsPrepared = false;
		}

		for (int j = 0; j < roomDimRow; j++)
			for (int i = 0; i < roomDimCol; i++)
			{
				quad = &vertexArray[(i + j * roomDimCol) * 4];

				quad[0].position.x += dirVec.x * static_cast<float>(transMag);
				quad[1].position.x += dirVec.x * static_cast<float>(transMag);
				quad[2].position.x += dirVec.x * static_cast<float>(transMag);
				quad[3].position.x += dirVec.x * static_cast<float>(transMag);

				if (roomDimCol * tileWidth - quad[0].position.x <= tileWidth)
					break;
			}
		break;
	case Direction::Right:
		if (vertexArray[0].position.x
         + dirVec.x * static_cast<float>(transMag) == 0)
		{
			dir = Direction::None;
			translating = false;
			tilePositionsPrepared = false;
		}

		for (int j = 0; j < roomDimRow; j++)
			for (int i = roomDimCol - 1; i >= 0; i--)
			{
				quad = &vertexArray[(i + j * roomDimCol) * 4];

				quad[0].position.x += dirVec.x * static_cast<float>(transMag);
				quad[1].position.x += dirVec.x * static_cast<float>(transMag);
				quad[2].position.x += dirVec.x * static_cast<float>(transMag);
				quad[3].position.x += dirVec.x * static_cast<float>(transMag);

				if (quad[1].position.x - tileWidth <= 0)
					break;
			}
		break;
	}
}

void GrassRoom::translateOut(Direction& dir)
{
	sf::Vector2f dirVec = getUnitVector(dir);
	sf::Vertex* quad;
	switch (dir)
	{
	case Direction::Up:
		if (vertexArray[(roomDimRow - 1) * roomDimCol * 4 + 2].position.y
			+ dirVec.y * static_cast<float>(transMag) < 0)
		{
			dir = Direction::None;
			translating = false;
		}
		
		for (int j = roomDimRow - 1; j >= 0; j--)
			for (int i = 0; i < roomDimCol; i++)
			{
				quad = &vertexArray[(i + j * roomDimCol) * 4];

				quad[0].position.y += dirVec.y * static_cast<float>(transMag);
				quad[1].position.y += dirVec.y * static_cast<float>(transMag);
				quad[2].position.y += dirVec.y * static_cast<float>(transMag);
				quad[3].position.y += dirVec.y * static_cast<float>(transMag);

				if (quad[2].position.y < 0 && i == roomDimCol - 1)
					return;
			}
		break;
	case Direction::Down:
		if (vertexArray[0].position.y + dirVec.y * static_cast<float>(transMag)
			> Constants::WINDOW_HEIGHT_PIXELS)
		{
			dir = Direction::None;
			translating = false;
		}

		for (int j = 0; j < roomDimRow; j++)
			for (int i = 0; i < roomDimCol; i++)
			{
				quad = &vertexArray[(i + j * roomDimCol) * 4];

				quad[0].position.y += dirVec.y * static_cast<float>(transMag);
				quad[1].position.y += dirVec.y * static_cast<float>(transMag);
				quad[2].position.y += dirVec.y * static_cast<float>(transMag);
				quad[3].position.y += dirVec.y * static_cast<float>(transMag);

				if (quad[0].position.y > Constants::WINDOW_HEIGHT_PIXELS
					&& i == roomDimCol - 1)
					return;
			}
		break;
	case Direction::Left:
		if (vertexArray[(roomDimCol - 1) * 4 + 1].position.x
         + dirVec.x * static_cast<float>(transMag) < 0)
		{
			dir = Direction::None;
			translating = false;
		}

		for (int j = 0; j < roomDimRow; j++)
			for (int i = roomDimCol - 1; i >= 0; i--)
			{
				quad = &vertexArray[(i + j * roomDimCol) * 4];

				quad[0].position.x += dirVec.x * static_cast<float>(transMag);
				quad[1].position.x += dirVec.x * static_cast<float>(transMag);
				quad[2].position.x += dirVec.x * static_cast<float>(transMag);
				quad[3].position.x += dirVec.x * static_cast<float>(transMag);

				if (quad[1].position.x < 0)
					break;
			}
		break;
	case Direction::Right:
		if (vertexArray[0].position.x + dirVec.x * static_cast<float>(transMag)
			> Constants::WINDOW_WIDTH_PIXELS)
		{
			dir = Direction::None;
			translating = false;
		}

		for (int j = 0; j < roomDimRow; j++)
			for (int i = 0; i < roomDimCol; i++)
			{
				quad = &vertexArray[(i + j * roomDimCol) * 4];

				quad[0].position.x += dirVec.x * static_cast<float>(transMag);
				quad[1].position.x += dirVec.x * static_cast<float>(transMag);
				quad[2].position.x += dirVec.x * static_cast<float>(transMag);
				quad[3].position.x += dirVec.x * static_cast<float>(transMag);

				if (quad[0].position.x > Constants::WINDOW_WIDTH_PIXELS)
					break;
			}
		break;
	}
}

void GrassRoom::draw(sf::RenderTarget& rt, sf::RenderStates states) const
{
	Room::draw(rt, states);

	if (!translating)
	{
		demon.draw(rt);
	}
	// TODO
	// rt.draw(demon.getSprite());
}

void GrassRoom::initTilePropertiesMat()
{
	for (int row = 0; row < tilePropertiesMat.size(); row++)
		for (int col = 0; col < tilePropertiesMat[0].size(); col++)
			tilePropertiesMat[row][col]
				= TileProperties(roomMatrix[row][col]);
}

void GrassRoom::prepareTilePositions(Direction& transInDir)
{
	sf::Vertex* quad;
	for (int j = 0; j < roomDimRow; j++)
		for (int i = 0; i < roomDimCol; i++)
		{
			quad = &vertexArray[(i + j * roomDimCol) * 4];

			switch (transInDir)
			{
			case Direction::Up:
				quad[0].position =
				{
					static_cast<float>(i * tileWidth),
					static_cast<float>(roomDimRow * tileHeight)
				};
				quad[1].position =
				{
					static_cast<float>((i + 1) * tileWidth),
					static_cast<float>(roomDimRow * tileHeight)
				};
				quad[2].position =
				{
					static_cast<float>((i + 1) * tileWidth),
					static_cast<float>((roomDimRow + 1) * tileHeight)
				};
				quad[3].position =
				{
					static_cast<float>(i * tileWidth),
					static_cast<float>((roomDimRow + 1) * tileHeight)
				};
				break;
			case Direction::Down:
				quad[0].position =
				{
					static_cast<float>(i * tileWidth),
					static_cast<float>(-tileHeight)
				};
				quad[1].position =
				{
					static_cast<float>((i + 1) * tileWidth),
					static_cast<float>(-tileHeight)
				};
				quad[2].position =
				{
					static_cast<float>((i + 1) * tileWidth),
					0
				};
				quad[3].position =
				{
					static_cast<float>(i * tileWidth),
					0
				};
				break;
			case Direction::Left:
				quad[0].position =
				{
					static_cast<float>(roomDimCol * tileWidth),
					static_cast<float>(j * tileHeight)
				};
				quad[1].position =
				{
					static_cast<float>((roomDimCol + 1) * tileWidth),
					static_cast<float>(j * tileHeight)
				};
				quad[2].position =
				{
					static_cast<float>((roomDimCol + 1) * tileWidth),
					static_cast<float>((j + 1) * tileHeight)
				};
				quad[3].position =
				{
					static_cast<float>(roomDimCol * tileWidth),
					static_cast<float>((j + 1) * tileHeight)
				};
				break;
			case Direction::Right:
				quad[0].position =
				{
					static_cast<float>(-tileWidth),
					static_cast<float>(j * tileHeight)
				};
				quad[1].position =
				{
					0,
					static_cast<float>(j * tileHeight)
				};
				quad[2].position =
				{
					0,
					static_cast<float>((j + 1) * tileHeight)
				};
				quad[3].position =
				{
					static_cast<float>(-tileWidth),
					static_cast<float>((j + 1) * tileHeight)
				};
				break;
			}
		}
	tilePositionsPrepared = true;
}

bool GrassRoom::checkForCollision(const Direction& mcDirX,
   const Direction& mcDirY, const sf::Vector2i& tileLocation,
	const AABB<sf::Vector2i>& tileAabb) const
{
	sf::Vector2i tileAabbAbsoluteMin
	{
		tileLocation.x * tileWidth + tileAabb.getMin().x,
		tileLocation.y * tileHeight + tileAabb.getMin().y
	};
	sf::Vector2i tileAabbAbsoluteMax
	{
		tileLocation.x * tileWidth + tileAabb.getMax().x,
		tileLocation.y * tileHeight + tileAabb.getMax().y
	};

	std::cout << "TileAabbAbsoluteMin: " << tileAabbAbsoluteMin.x
		<< " " << tileAabbAbsoluteMin.y << std::endl;
	std::cout << "TileAabbAbsoluteMax: " << tileAabbAbsoluteMax.x
		<< " " << tileAabbAbsoluteMax.y << std::endl;
	std::cout << "MCAabbMin: " << mcPointer->getAabbMin().x
		<< " " << mcPointer->getAabbMin().y << std::endl;
	std::cout << "MCAabbMax: " << mcPointer->getAabbMax().x
		<< " " << mcPointer->getAabbMax().y << std::endl;

	float diffx1 = static_cast<float>(tileAabbAbsoluteMax.x)
		- mcPointer->getAabbMin().x;
	float diffx2 = mcPointer->getAabbMax().x
		- static_cast<float>(tileAabbAbsoluteMin.x);
	float diffy1 = static_cast<float>(tileAabbAbsoluteMin.y)
		- mcPointer->getAabbMax().y;
	float diffy2 = mcPointer->getAabbMin().y
		- static_cast<float>(tileAabbAbsoluteMax.y);

	if (diffx1 > -1 && diffx2 > -1 && diffy1 > -1 && diffy2 > -1)
	{
		//collision
		std::cout << "Collision!" << std::endl;
		if (mcDirY == Direction::Up)
			mcPointer->moveDistanceY(diffy1);
		else if (mcDirY == Direction::Down)
			mcPointer->moveDistanceY(-diffy2);
		if (mcDirX == Direction::Left)
			mcPointer->moveDistanceX(diffx1 + 1);
		else if (mcDirX == Direction::Right)
			mcPointer->moveDistanceX(-diffx2);
		std::cout << "MCAabbMinNew: " << mcPointer->getAabbMin().x
			<< " " << mcPointer->getAabbMin().y << std::endl;
		std::cout << "MCAabbMaxNew: " << mcPointer->getAabbMax().x
			<< " " << mcPointer->getAabbMax().y << std::endl;
		std::cout << std::endl;
		return true;
	}
	else
		return false;
}
