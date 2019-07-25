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
protected:
	void draw(sf::RenderTarget& rt, sf::RenderStates states) const override;
private:
	static constexpr unsigned char roomDimCol = 25;
	static constexpr unsigned char roomDimRow = 25;
	Matrix<unsigned int, roomDimCol, roomDimRow> roomMatrix;

	static constexpr float demonStartPosX = 400.0f;
	static constexpr float demonStartPosY = 300.0f;
	DemonCharacter demon;
};