#include "BlackRoom.h"

BlackRoom::BlackRoom()
	:
	Room("Sprites/Environment/grass_tile.png", "BlackRoom",
		64, 64),
	roomMatrix{ {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	} }
{
}

bool BlackRoom::load()
{
	// load the tileset texture
	if (!texture.loadFromFile(fileName))
	{
		std::cerr << "Problem loading " << fileName << " to texture in "
			<< roomName << " load." << std::endl;
		return false;
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

			// define its 4 corners
			quad[0].position = sf::Vector2f(static_cast<float>(i * tileWidth),
				static_cast<float>(j * tileHeight));
			quad[1].position = sf::Vector2f(static_cast<float>((i + 1) * tileWidth),
				static_cast<float>(j * tileHeight));
			quad[2].position = sf::Vector2f(static_cast<float>((i + 1) * tileWidth),
				static_cast<float>((j + 1) * tileHeight));
			quad[3].position = sf::Vector2f(static_cast<float>(i * tileWidth),
				static_cast<float>((j + 1) * tileHeight));

			// define its 4 texture coordinates
			quad[0].texCoords = sf::Vector2f(static_cast<float>(tu * tileWidth),
				static_cast<float>(tv * tileHeight));
			quad[1].texCoords = sf::Vector2f(static_cast<float>((tu + 1) * tileWidth),
				static_cast<float>(tv * tileHeight));
			quad[2].texCoords = sf::Vector2f(static_cast<float>((tu + 1) * tileWidth),
				static_cast<float>((tv + 1) * tileHeight));
			quad[3].texCoords = sf::Vector2f(static_cast<float>(tu * tileWidth),
				static_cast<float>((tv + 1) * tileHeight));
		}
	roomLoaded = true;
	return true;
}

void BlackRoom::translateIn(TranslationDir& dir)
{
}

void BlackRoom::translateOut(TranslationDir& dir)
{
	sf::Vector2f dirVec;
	sf::Vertex* quad;
	switch (dir)
	{
	case TranslationDir::Up:
		dirVec = { 0, -1 };
		if (vertexArray[(roomDimRow - 1) * roomDimCol * 4 + 2].position.y
			+ dirVec.y * static_cast<float>(transMag) < 0)
		{
			dir = TranslationDir::None;
			resetVertexArrayPositions();
			return;
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
	case TranslationDir::Down:
		dirVec = { 0, 1 };
		if (vertexArray[0].position.y + dirVec.y * static_cast<float>(transMag)
				> Constants::WINDOW_HEIGHT_PIXELS)
		{
			dir = TranslationDir::None;
			resetVertexArrayPositions();
			return;
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
	case TranslationDir::Left:
		dirVec = { -1, 0 };
		if (vertexArray[(roomDimCol - 1) * 4 + 1].position.x + dirVec.x
			* static_cast<float>(transMag) < 0)
		{
			dir = TranslationDir::None;
			resetVertexArrayPositions();
			return;
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
	case TranslationDir::Right:
		dirVec = { 1, 0 };
		if (vertexArray[0].position.x + dirVec.x * static_cast<float>(transMag)
				> Constants::WINDOW_WIDTH_PIXELS)
		{
			dir = TranslationDir::None;
			resetVertexArrayPositions();
			return;
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

void BlackRoom::populateVertexStartingPositions()
{
	for (int i = 0; i < vertexStartingPositions.size(); i++)
		vertexStartingPositions[i] = vertexArray[i].position;
}

void BlackRoom::resetVertexArrayPositions()
{
	for (int i = 0; i < vertexStartingPositions.size(); i++)
		vertexArray[i].position = vertexStartingPositions[i];
}
