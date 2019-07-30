#pragma once
#include <array>
#include "Room.h"
#include "Matrix.h"

class WorldMap
{
public:
	WorldMap();
	bool up();
	bool down();
	bool left();
	bool right();
	Room& getCurrentRoom();
	void handleRoomDrawing(sf::RenderTarget& rt);
private:
	void loadCurrentRoom();
private:
	static constexpr unsigned char worldMapDimRow = 3;
	static constexpr unsigned char worldMapDimCol = 3;
	Matrix<Room*, worldMapDimRow, worldMapDimCol> worldMatrix;

	unsigned char worldMatRow, worldMatCol;
	Room* currentRoom, *prevRoom;

	Direction direction;
};