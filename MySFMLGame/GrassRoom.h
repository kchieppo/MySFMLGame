#pragma once
#include "Room.h"
#include "Matrix.h"

class GrassRoom : public Room
{
public:
	GrassRoom();
	bool load() override;
private:
	static constexpr unsigned char roomDimCol = 25;
	static constexpr unsigned char roomDimRow = 25;
	Matrix<unsigned int, roomDimCol, roomDimRow> roomMatrix;
};