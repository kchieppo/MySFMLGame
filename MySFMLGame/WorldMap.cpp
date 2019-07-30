#include "WorldMap.h"
#include "GrassRoom.h"
#include "BlueRoom.h"
#include "PurpleRoom.h"
#include "BlackRoom.h"

WorldMap::WorldMap()
	:
	worldMatrix{ {
		{new BlueRoom(), new BlackRoom(), new BlueRoom()},
		{new GrassRoom(), new BlueRoom(), new GrassRoom()},
		{new BlueRoom(), new PurpleRoom(), new BlueRoom()}
	} },
	worldMatRow{ 1 },
	worldMatCol{ 1 },
	currentRoom{ worldMatrix.at(worldMatRow).at(worldMatCol) },
	prevRoom{ currentRoom },
	direction{ Direction::None }
{
	loadCurrentRoom();
}

bool WorldMap::up()
{
	if (worldMatRow != 0)
	{
		direction = Direction::Down;
		prevRoom = currentRoom;
		currentRoom = worldMatrix.at(--worldMatRow).at(worldMatCol);
		currentRoom->setTranslatingIn(true);
		loadCurrentRoom();
		return true;
	}
	return false;
}

bool WorldMap::down()
{
	if (worldMatRow != worldMapDimRow - 1)
	{
		direction = Direction::Up;
		prevRoom = currentRoom;
		currentRoom = worldMatrix.at(++worldMatRow).at(worldMatCol);
		currentRoom->setTranslatingIn(true);
		loadCurrentRoom();
		return true;
	}
	return false;
}

bool WorldMap::left()
{
	if (worldMatCol != 0)
	{
		direction = Direction::Right;
		prevRoom = currentRoom;
		currentRoom = worldMatrix.at(worldMatRow).at(--worldMatCol);
		currentRoom->setTranslatingIn(true);
		loadCurrentRoom();
		return true;
	}
	return false;
}

bool WorldMap::right()
{
	if (worldMatCol != worldMapDimCol - 1)
	{
		direction = Direction::Left;
		prevRoom = currentRoom;
		currentRoom = worldMatrix.at(worldMatRow).at(++worldMatCol);
		currentRoom->setTranslatingIn(true);
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
	if (direction == Direction::None)
		rt.draw(*currentRoom);
	else
	{
		currentRoom->translateIn(direction);
		prevRoom->translateOut(direction);
		if (direction != Direction::None)
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
