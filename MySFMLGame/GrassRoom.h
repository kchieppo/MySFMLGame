#pragma once
#include "Room.h"
#include "Matrix.h"
#include "DemonCharacter.h"

class GrassRoom : public Room
{
public:
	GrassRoom();
	bool load() override;
	void update(const float& dt) override;
	void reset() override;
	void translateIn(Direction& dir) override;
	void translateOut(Direction& dir) override;
protected:
	void draw(sf::RenderTarget& rt, sf::RenderStates states) const override;
private:
	void prepareTilePositions(Direction& transInDir);
private:
	static constexpr int roomDimCol = 12;
	static constexpr int roomDimRow = 10;
	Matrix<unsigned int, roomDimRow, roomDimCol> roomMatrix;

	bool tilePositionsPrepared;

	static constexpr float demonStartPosX = 400.0f;
	static constexpr float demonStartPosY = 300.0f;
	DemonCharacter demon;
};