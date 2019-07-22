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
	static constexpr unsigned char worldMapDimX = 2;
	static constexpr unsigned char worldMapDimY = 2;
	Matrix<Room*, worldMapDimX, worldMapDimY> worldMatrix;

	unsigned char locationX, locationY;
	Room* currentRoom;
};