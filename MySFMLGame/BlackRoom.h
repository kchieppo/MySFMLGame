#pragma once
#include "Room.h"
#include "Matrix.h"

class BlackRoom : public Room
{
public:
	BlackRoom();
	bool load() override;
	void update(const float& dt) override;
	void translateIn(Direction& dir) override;
	void translateOut(Direction& dir) override;
private:
	void prepareTilePositions(Direction& transInDir);
private:
	static constexpr int roomDimCol = 12;
	static constexpr int roomDimRow = 10;
	Matrix<unsigned int, roomDimRow, roomDimCol> roomMatrix;

	bool tilePositionsPrepared;
};