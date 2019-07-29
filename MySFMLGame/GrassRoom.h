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
	void translateIn(TranslationDir& dir) override;
	void translateOut(TranslationDir& dir) override;
protected:
	void draw(sf::RenderTarget& rt, sf::RenderStates states) const override;
private:
	void populateVertexStartingPositions();
	void resetVertexArrayPositions();
private:
	static constexpr unsigned char roomDimCol = 12;
	static constexpr unsigned char roomDimRow = 10;
	Matrix<unsigned int, roomDimRow, roomDimCol> roomMatrix;

	std::array<sf::Vector2f, roomDimRow*roomDimCol*4>
		vertexStartingPositions;

	static constexpr float demonStartPosX = 400.0f;
	static constexpr float demonStartPosY = 300.0f;
	DemonCharacter demon;
};