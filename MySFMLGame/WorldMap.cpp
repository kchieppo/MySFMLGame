#include "WorldMap.h"
#include "GrassRoom.h"

WorldMap::WorldMap()
	:
	worldMatrix{ {
		{new GrassRoom(), new GrassRoom()},
		{new GrassRoom(), new GrassRoom()}
	} },
	locationX{ 0 },
	locationY{ 0 },
	currentRoom{ worldMatrix.at(locationX).at(locationY) }
{
	loadCurrentRoom();
}

void WorldMap::up()
{
	if (locationY != 0)
	{
		locationY -= 1;
		currentRoom = worldMatrix.at(locationX).at(locationY);
		loadCurrentRoom();
	}
}

void WorldMap::down()
{
	if (locationY != worldMapDimY - 1)
	{
		locationY += 1;
		currentRoom = worldMatrix.at(locationX).at(locationY);
		loadCurrentRoom();
	}
}

void WorldMap::left()
{
	if (locationX != 0)
	{
		locationX -= 1;
		currentRoom = worldMatrix.at(locationX).at(locationY);
		loadCurrentRoom();
	}
}

void WorldMap::right()
{
	if (locationX != worldMapDimX - 1)
	{
		locationX += 1;
		currentRoom = worldMatrix.at(locationX).at(locationY);
		loadCurrentRoom();
	}
}

const Room& WorldMap::getCurrentRoom()
{
	return *worldMatrix.at(locationX).at(locationY);
}

void WorldMap::loadCurrentRoom()
{
	if (!currentRoom->isLoaded())
		currentRoom->load();
}
