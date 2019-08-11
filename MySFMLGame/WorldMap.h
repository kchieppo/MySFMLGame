#pragma once
#include <array>
#include "Room.h"
#include "MainCharacter.h"
#include "Matrix.h"

class WorldMap
{
public:
	WorldMap();
	bool up();
	bool down();
	bool left();
	bool right();
	void updateCurrentRoom(const float& dt);
	void adjustForCollisionsWithRoom();
	void handleRoomDrawing(sf::RenderTarget& rt);
	MainCharacter* const getMainCharacterPtr();
private:
	void loadCurrentRoom();
private:
	static constexpr unsigned char worldMapDimRow = 3;
	static constexpr unsigned char worldMapDimCol = 3;
	Matrix<Room*, worldMapDimRow, worldMapDimCol> worldMatrix;

	unsigned char worldMatRow, worldMatCol;
	Room* currentRoom, *prevRoom;

	Direction translationDir;

	MainCharacter mainCharacter;
};