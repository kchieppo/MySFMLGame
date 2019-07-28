#pragma once
#include "Room.h"
#include "Matrix.h"

class BlackRoom : public Room
{
public:
	BlackRoom();
	bool load() override;
	void translateIn(TranslationDir& dir) override;
	void translateOut(TranslationDir& dir) override;
private:
	void populateVertexStartingPositions();
	void resetVertexArrayPositions();
private:
	static constexpr unsigned char roomDimCol = 25;
	static constexpr unsigned char roomDimRow = 25;
	Matrix<unsigned int, roomDimCol, roomDimRow> roomMatrix;

	std::array<sf::Vector2f, roomDimRow*roomDimCol * 4>
		vertexStartingPositions;
};