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

   // Based on the main character's AABB location, this figures out what tiles
   // the main character is standing over. checkForCollision is called on a
   // subset of these tiles that have AABBs.
	void findTilesStandingOver() override;
protected:
	void draw(sf::RenderTarget& rt, sf::RenderStates states) const override;
private:
	void initTilePropertiesMat();

   // Called before this room is translated in from off screen. This method
   // sets the positions of the tiles to be off screen on the side of the screen
   // from which they will come.
	void prepareTilePositions(Direction& transInDir);

   // Checks for a collision between the main character's AABB and the tile's
   // AABB contained within tileProperties. If a collision is detected, the main
   // character's position is adjusted based on the main character's AABB's
   // displacement and the main character's direction of motion.
	bool checkForCollision(const Direction& mcDirX, const Direction& mcDirY,
		const TileProperties& tileProperties)
		const;
private:
	static constexpr int roomDimCol = 48;
	static constexpr int roomDimRow = 40;

   /*
   roomMatrix is simply a matrix of tile numbers and represents the layout of
   the room. tilePropertiesMat is a matrix of the same dimensions containing
   instances of TileProperties, which each contain the corresponding tile number
   and properties associated with that tile number.

   Only tilePropertiesMat is truly needed, but separating out the tile numbers
   into a separate matrix (roomMatrix) makes it very easy to see and manually
   manipulate the tiles in a room.
   */
	Matrix<int, roomDimRow, roomDimCol> roomMatrix;
	Matrix<TileProperties, roomDimRow, roomDimCol> tilePropertiesMat;

	bool tilePositionsPrepared;

   // The difference between the current min of the AABB and the previous min
   // is taken to get the main character's direction of motion.
	sf::Vector2f mainCharAabbMinLast;

   // NPC character
	static constexpr float demonStartPosX = 400.0f;
	static constexpr float demonStartPosY = 300.0f;
	DemonCharacter demon;
};