#include "WorldMap.h"
#include "GrassRoom.h"
#include "BlueRoom.h"
#include "PurpleRoom.h"
#include "BlackRoom.h"

WorldMap::WorldMap()
	:
	worldMatrix{ {
		{new GrassRoom(), new BlueRoom(), new PurpleRoom()},
		{new PurpleRoom(), new BlackRoom(), new BlueRoom()}
	} },
	worldMatRow{ 0 },
	worldMatCol{ 1 },
	currentRoom{ worldMatrix.at(worldMatRow).at(worldMatCol) },
	prevRoom{ currentRoom },
	translationDir{ TranslationDir::None }
{
	loadCurrentRoom();
}

bool WorldMap::up()
{
	if (worldMatRow != 0)
	{
		translationDir = TranslationDir::Down;
		prevRoom = currentRoom;
		currentRoom = worldMatrix.at(--worldMatRow).at(worldMatCol);
		loadCurrentRoom();
		return true;
	}
	return false;
}

bool WorldMap::down()
{
	if (worldMatRow != worldMapDimRow - 1)
	{
		translationDir = TranslationDir::Up;
		prevRoom = currentRoom;
		currentRoom = worldMatrix.at(++worldMatRow).at(worldMatCol);
		loadCurrentRoom();
		return true;
	}
	return false;
}

bool WorldMap::left()
{
	if (worldMatCol != 0)
	{
		translationDir = TranslationDir::Right;
		prevRoom = currentRoom;
		currentRoom = worldMatrix.at(worldMatRow).at(--worldMatCol);
		loadCurrentRoom();
		return true;
	}
	return false;
}

bool WorldMap::right()
{
	if (worldMatCol != worldMapDimCol - 1)
	{
		translationDir = TranslationDir::Left;
		prevRoom = currentRoom;
		currentRoom = worldMatrix.at(worldMatRow).at(++worldMatCol);
		loadCurrentRoom();
		return true;
	}
	return false;
}

Room& WorldMap::getCurrentRoom()
{
	return *worldMatrix.at(worldMatRow).at(worldMatCol);
}

void WorldMap::handleRoomDrawing(sf::RenderTarget& rt)
{
	if (translationDir == TranslationDir::None)
		rt.draw(*currentRoom);
	else
	{
		currentRoom->translateIn(translationDir);
		prevRoom->translateOut(translationDir);
		if (translationDir != TranslationDir::None)
		{
			rt.draw(*currentRoom);
			rt.draw(*prevRoom);
		}
	}
}

void WorldMap::loadCurrentRoom()
{
	if (!currentRoom->isLoaded())
		currentRoom->load();
	currentRoom->reset();
}
