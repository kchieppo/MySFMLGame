#pragma once
#include "Room.h"
#include "Matrix.h"

class PurpleRoom : public Room
{
public:
	PurpleRoom();
	bool load() override;
	void translateIn(TranslationDir& dir) override;
	void translateOut(TranslationDir& dir) override;
private:
	void populateVertexStartingPositions();
	void resetVertexArrayPositions();
private:
	static constexpr unsigned char roomDimCol = 12;
	static constexpr unsigned char roomDimRow = 10;
	Matrix<unsigned int, roomDimRow, roomDimCol> roomMatrix;

	std::array<sf::Vector2f, roomDimRow*roomDimCol * 4>
		vertexStartingPositions;
};