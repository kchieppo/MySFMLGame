#pragma once
#include <array>
#include "Room.h"
#include "MainCharacter.h"
#include "Matrix.h"

/*
Contains the matrix containing the game world. Each matrix element is a pointer
to a Room, where Room is the base class to all types of rooms.
*/
class WorldMap
{
public:
	WorldMap();
   // Called when the main character moves into the room up from the current
   // room. The currentRoom pointer is set to point to the upper room, and the
   // prevRoom pointer is set to the current room. Flags for the current room
   // and the upper room are set to indicate that they will be animating out and
   // animating in respectively. Finally, the new room is initialized.
	bool up();
	bool down();
	bool left();
	bool right();

   // Calls currentRoom->update(dt), which updates the current room's temporal
   // objects, given delta time dt. Called every frame.
	void updateCurrentRoom(const float& dt);

   // Calls currentRoom->checkForCollisions(), which checks whether the main
   // character's AABB is colliding with any of the AABBs of the tiles he is
   // standing over. Called every frame.
	void adjustForCollisionsWithRoom();

   // Normally, this calls rt.draw(*currentRoom), which draws the current room
   // to the screen. If transitioning to a new room, the current room and the
   // new room are translated a small amount and drawn to the screen. Called
   // every frame.
	void handleRoomDrawing(sf::RenderTarget& rt);

   // Returns true if next room is translating into view
   bool roomIsTranslating();

	MainCharacter* const getMainCharacterPtr();
private:
   // Initializes the current room if it hasn't been. Also resets the current
   // room to its initial state.
	void loadCurrentRoom();
private:
   // The dimensions of the game world matrix.
	static constexpr unsigned char worldMapDimRow = 3;
	static constexpr unsigned char worldMapDimCol = 3;
	Matrix<Room*, worldMapDimRow, worldMapDimCol> worldMatrix;

   // The row and column of the current room.
	unsigned char curWorldMatRow, curWorldMatCol;

	Room* currentRoom, *prevRoom;

   // The direction in which the previous room and current room translate when
   // the main character enters a new room.
	Direction translationDir;

	MainCharacter mainCharacter;
};