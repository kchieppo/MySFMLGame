#include "WorldMap.h"
#include "GrassRoom.h"
#include "BlueRoom.h"

WorldMap::WorldMap()
	:
	worldMatrix{ {
		{new BlueRoom(), new GrassRoom()},
		{new GrassRoom(), new GrassRoom()}
	} },
	worldMatRow{ 0 },
	worldMatCol{ 1 },
	currentRoom{ worldMatrix.at(worldMatRow).at(worldMatCol) }
{
	loadCurrentRoom();
}

void WorldMap::up()
{
	if (worldMatRow != 0)
	{
		worldMatRow -= 1;
		currentRoom = worldMatrix.at(worldMatRow).at(worldMatCol);
		loadCurrentRoom();
	}
}

void WorldMap::down()
{
	if (worldMatRow != worldMapDimRow - 1)
	{
		worldMatRow += 1;
		currentRoom = worldMatrix.at(worldMatRow).at(worldMatCol);
		loadCurrentRoom();
	}
}

void WorldMap::left()
{
	if (worldMatCol != 0)
	{
		worldMatCol -= 1;
		currentRoom = worldMatrix.at(worldMatRow).at(worldMatCol);
		loadCurrentRoom();
	}
}

void WorldMap::right()
{
	if (worldMatCol != worldMapDimCol - 1)
	{
		worldMatCol += 1;
		currentRoom = worldMatrix.at(worldMatRow).at(worldMatCol);
		loadCurrentRoom();
	}
}

const Room& WorldMap::getCurrentRoom()
{
	return *worldMatrix.at(worldMatRow).at(worldMatCol);
}

void WorldMap::loadCurrentRoom()
{
	if (!currentRoom->isLoaded())
		currentRoom->load();
}
