#include "BlueRoom.h"

BlueRoom::BlueRoom()
	:
	Room("Sprites/Environment/grass_tile.png", "BlueRoom", 64, 64, false),
	roomMatrix{ {
		{0, 3, 1, 3, 2, 3, 0, 3, 1, 3, 2, 3},
		{3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
		{1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
		{3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
		{2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
		{3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
		{0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
		{3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
		{1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
		{3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}
	} },
	tilePositionsPrepared{ false }
{
}

void BlueRoom::load(MainCharacter* mcP)
{
	Room::load(mcP);

	// load the tileset texture
	if (!texture.loadFromFile(fileName))
	{
		std::cerr << "Problem loading " << fileName << " to texture in "
			<< roomName << " load." << std::endl;
	}

	// resize the vertex array to fit the level size
	vertexArray.setPrimitiveType(sf::Quads);
	vertexArray.resize(roomDimCol * roomDimRow * 4);

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
			else
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

void BlueRoom::update(const float& dt)
{
	if (!translating)
	{

	}
}

void BlueRoom::translateIn(Direction& dir)
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

void BlueRoom::translateOut(Direction& dir)
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

void BlueRoom::prepareTilePositions(Direction& transInDir)
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
