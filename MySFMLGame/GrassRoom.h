#pragma once
#include "Room.h"
#include "TileProperties.h"
#include "Matrix.h"
#include "DemonCharacter.h"

class GrassRoom : public Room
{
public:
	GrassRoom();
	void load(MainCharacter* mcP) override;
	void update(const float& dt) override;
	void reset() override;
	void translateIn(Direction& dir) override;
	void translateOut(Direction& dir) override;
	void findTilesStandingOver() override;
protected:
	void draw(sf::RenderTarget& rt, sf::RenderStates states) const override;
private:
	void initTilePropertiesMat();
	void prepareTilePositions(Direction& transInDir);
	bool checkForCollision(const Direction& mcDirX,
		const Direction& mcDirY,
		const sf::Vector2i& tileLocation,
		const AABB<sf::Vector2i>& tileAabb) const;
private:
	static constexpr int roomDimCol = 48;
	static constexpr int roomDimRow = 40;
	Matrix<int, roomDimRow, roomDimCol> roomMatrix;
	Matrix<TileProperties, roomDimRow, roomDimCol> tilePropertiesMat;

	bool tilePositionsPrepared;

	sf::Vector2f mainCharAabbMinLast;

	static constexpr float demonStartPosX = 400.0f;
	static constexpr float demonStartPosY = 300.0f;
	DemonCharacter demon;
};