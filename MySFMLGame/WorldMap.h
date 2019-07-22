#pragma once
#include <array>
#include "Room.h"
#include "Matrix.h"

class WorldMap
{
public:
	WorldMap();
	void up();
	void down();
	void left();
	void right();
	const Room& getCurrentRoom();
private:
	void loadCurrentRoom();
private:
	static constexpr unsigned char worldMapDimRow = 2;
	static constexpr unsigned char worldMapDimCol = 2;
	Matrix<Room*, worldMapDimRow, worldMapDimCol> worldMatrix;

	unsigned char worldMatRow, worldMatCol;
	Room* currentRoom;
};