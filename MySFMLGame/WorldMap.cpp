#include "WorldMap.h"
#include "GrassRoom.h"
#include "BlueRoom.h"
#include "PurpleRoom.h"
#include "BlackRoom.h"

/*
The new rooms in worldMatrix are never deleted because worldMatrix persists. In
the future, may save room states, then destruct rooms as the main character
leaves them to save on memory.
*/

WorldMap::WorldMap()
	:
	worldMatrix{ {
		{new GrassRoom(), new GrassRoom(), new GrassRoom()},
		{new GrassRoom(), new GrassRoom(), new GrassRoom()},
		{new GrassRoom(), new GrassRoom(), new GrassRoom()}
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
	if (!mainCharacter.getPositionChanged())
		return;
	mainCharacter.setPositionChanged(false);

	currentRoom->checkForCollisions();

	// if a boundary was hit, go to the next room
	switch (currentRoom->getBoundaryHit()){
	case BoundaryHit::Down:
		if (down())
			mainCharacter.setPositionY(0);
		else
			mainCharacter.setPositionY
			(
				static_cast<float>(Constants::WINDOW_HEIGHT_PIXELS
					- mainCharacter.getSpriteHeight())
			);
		currentRoom->setBoundaryHit(BoundaryHit::None);
		break;
	case BoundaryHit::Left:
		if (left())
			mainCharacter.setPositionX
			(
				static_cast<float>(Constants::WINDOW_WIDTH_PIXELS
					- mainCharacter.getSpriteWidth())
			);
		else
			mainCharacter.setPositionX(0);
		currentRoom->setBoundaryHit(BoundaryHit::None);
		break;
	case BoundaryHit::Right:
		if (right())
			mainCharacter.setPositionX(0);
		else
			mainCharacter.setPositionX
			(
				static_cast<float>(Constants::WINDOW_WIDTH_PIXELS
					- mainCharacter.getSpriteWidth())
			);
		currentRoom->setBoundaryHit(BoundaryHit::None);
		break;
	case BoundaryHit::Up:
		if (up())
			mainCharacter.setPositionY
			(
				static_cast<float>(Constants::WINDOW_HEIGHT_PIXELS
					- mainCharacter.getSpriteHeight())
			);
		else
			mainCharacter.setPositionY(0);
		currentRoom->setBoundaryHit(BoundaryHit::None);
		break;
	}
}

void WorldMap::handleRoomDrawing(sf::RenderTarget& rt)
{
   // Just draw current room to screen if not transitioning to new one.
	if (translationDir == Direction::None)
		rt.draw(*currentRoom);
	else
	{
		currentRoom->translateIn(translationDir);
      // If currentRoom->translateIn changes translationDir to Direction::None,
      // it is done translating in, so the previous room doesn't need to be
      // drawn an additional time.
		if (translationDir != Direction::None)
		{
			prevRoom->translateOut(translationDir);
			rt.draw(*prevRoom);
		}
		rt.draw(*currentRoom);
	}
}

bool WorldMap::roomIsTranslating()
{
	if (translationDir == Direction::None)
		return false;
	else
		return true;
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
