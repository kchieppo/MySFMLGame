#pragma once
#include "Room.h"
#include "Matrix.h"

class BlueRoom : public Room
{
public:
	BlueRoom();
	bool load() override;
private:
	static constexpr unsigned char roomDimCol = 25;
	static constexpr unsigned char roomDimRow = 25;
	Matrix<unsigned int, roomDimCol, roomDimRow> roomMatrix;
};