#include "WorldMap.h"
#include "GrassRoom.h"
#include "BlueRoom.h"
#include "PurpleRoom.h"
#include "BlackRoom.h"

WorldMap::WorldMap()
	:
	worldMatrix{ {
		{new BlueRoom(), new PurpleRoom(), new BlueRoom()},
		{new BlackRoom(), new GrassRoom(), new BlackRoom()},
		{new BlueRoom(), new PurpleRoom(), new BlueRoom()}
	} },
	curWorldMatRow{ 1 },
	curWorldMatCol{ 1 },
	currentRoom{ worldMatrix.at(curWorldMatRow).at(curWorldMatCol) },
	prevRoom{ currentRoom },
	translationDir{ Direction::None },
	mainCharacter{ {400.0f, 400.0f} }
{
	loadCurrentRoom();
}

bool WorldMap::up()
{
	if (curWorldMatRow != 0)
	{
		translationDir = Direction::Down;
		prevRoom = currentRoom;
		currentRoom = worldMatrix.at(--curWorldMatRow).at(curWorldMatCol);
		prevRoom->setTranslating(true);
		currentRoom->setTranslating(true);
		loadCurrentRoom();
		return true;
	}
	return false;
}

bool WorldMap::down()
{
	if (curWorldMatRow != worldMapDimRow - 1)
	{
		translationDir = Direction::Up;
		prevRoom = currentRoom;
		currentRoom = worldMatrix.at(++curWorldMatRow).at(curWorldMatCol);
		prevRoom->setTranslating(true);
		currentRoom->setTranslating(true);
		loadCurrentRoom();
		return true;
	}
	return false;
}

bool WorldMap::left()
{
	if (curWorldMatCol != 0)
	{
		translationDir = Direction::Right;
		prevRoom = currentRoom;
		currentRoom = worldMatrix.at(curWorldMatRow).at(--curWorldMatCol);
		prevRoom->setTranslating(true);
		currentRoom->setTranslating(true);
		loadCurrentRoom();
		return true;
	}
	return false;
}

bool WorldMap::right()
{
	if (curWorldMatCol != worldMapDimCol - 1)
	{
		translationDir = Direction::Left;
		prevRoom = currentRoom;
		currentRoom = worldMatrix.at(curWorldMatRow).at(++curWorldMatCol);
		prevRoom->setTranslating(true);
		currentRoom->setTranslating(true);
		loadCurrentRoom();
		return true;
	}
	return false;
}

void WorldMap::updateCurrentRoom(const float& dt)
{
	currentRoom->update(dt);
}

void WorldMap::adjustForCollisionsWithRoom()
{
	currentRoom->findTilesStandingOver();
}

void WorldMap::handleRoomDrawing(sf::RenderTarget& rt)
{
	if (translationDir == Direction::None)
		rt.draw(*currentRoom);
	else
	{
		currentRoom->translateIn(translationDir);
		if (translationDir != Direction::None)
		{
			prevRoom->translateOut(translationDir);
			rt.draw(*prevRoom);
		}
		rt.draw(*currentRoom);
	}
}

MainCharacter* const WorldMap::getMainCharacterPtr()
{
	return currentRoom->getMainCharacterPtr();
}

void WorldMap::loadCurrentRoom()
{
	if (!currentRoom->isLoaded())
		currentRoom->load(&mainCharacter);
	currentRoom->reset();
}
