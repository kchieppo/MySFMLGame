#include "WorldMap.h"
#include "GrassRoom.h"
#include "BlueRoom.h"
#include "PurpleRoom.h"
#include "BlackRoom.h"

WorldMap::WorldMap()
	:
	worldMatrix{ {
		{new GrassRoom(), new BlackRoom(), new PurpleRoom()},
		{new PurpleRoom(), new BlueRoom(), new BlackRoom()}
	} },
	worldMatRow{ 0 },
	worldMatCol{ 1 },
	currentRoom{ worldMatrix.at(worldMatRow).at(worldMatCol) }
{
	loadCurrentRoom();
}

bool WorldMap::up()
{
	if (worldMatRow != 0)
	{
		worldMatRow -= 1;
		currentRoom = worldMatrix.at(worldMatRow).at(worldMatCol);
		loadCurrentRoom();
		return true;
	}
	return false;
}

bool WorldMap::down()
{
	if (worldMatRow != worldMapDimRow - 1)
	{
		worldMatRow += 1;
		currentRoom = worldMatrix.at(worldMatRow).at(worldMatCol);
		loadCurrentRoom();
		return true;
	}
	return false;
}

bool WorldMap::left()
{
	if (worldMatCol != 0)
	{
		worldMatCol -= 1;
		currentRoom = worldMatrix.at(worldMatRow).at(worldMatCol);
		loadCurrentRoom();
		return true;
	}
	return false;
}

bool WorldMap::right()
{
	if (worldMatCol != worldMapDimCol - 1)
	{
		worldMatCol += 1;
		currentRoom = worldMatrix.at(worldMatRow).at(worldMatCol);
		loadCurrentRoom();
		return true;
	}
	return false;
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
