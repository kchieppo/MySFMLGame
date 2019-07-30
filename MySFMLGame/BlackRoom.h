#pragma once
#include "Room.h"
#include "Matrix.h"

class BlackRoom : public Room
{
public:
	BlackRoom();
	bool load() override;
	void translateIn(Direction& dir) override;
	void translateOut(Direction& dir) override;
private:
	static constexpr int roomDimCol = 12;
	static constexpr int roomDimRow = 10;
	Matrix<unsigned int, roomDimRow, roomDimCol> roomMatrix;
};