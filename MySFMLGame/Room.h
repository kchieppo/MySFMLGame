#pragma once
#include "BoundaryHit.h"
#include "Constants.h"
#include "Direction.h"
#include "MainCharacter.h"
#include <array>
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

/*
The base class of all types of rooms in the game.
*/
class Room : public sf::Drawable, public sf::Transformable
{
public:
   /*
   fileName: relative path to the texture file used for the room
   roomName: preferably a unique name for the room
   tileWidth: the width of the tiles that will be used from the texture
   tileHeight: the height of the tiles that will be used from the texture
   firstRoom: set to true if this is the first room that will be drawn to the
      screen

   tileWidth and tileHeight are changeable parameters and not static constexprs
   because the art to be used for the game is not set in stone. Wanted to allow
   freedom to try art from different sources that may have different tile sizes.
   */
	Room(const std::string& fileName, const std::string& roomName,
      const int& tileWidth, const int& tileHeight, const bool& firstRoom);

   // Returns true if the room has been initialized.
	const bool& isLoaded() const;

   const BoundaryHit& getBoundaryHit() const;
   void setBoundaryHit(const BoundaryHit& boundHit);

   /*
   Base version just copies a pointer to the main character to the local
   mcPointer. Derived versions call the base version and initialize the room.
   The pointer to the main character is needed later for collision detection.
   */
	virtual void load(MainCharacter* mcP);

   // Updates temporal objects in the room, where dt is the time passed each
   // frame.
	virtual void update(const float& dt);

   // Resets the room to its initial state.
	virtual void reset();

   // Called when the main character walks into this room and the room needs to
   // slide into view. dir is the direction it will slide in.
	virtual void translateIn(Direction& dir);

   // Called when the main character leaves this room and the room needs to
   // slide out of view. dir is the direction it will slide out.
	virtual void translateOut(Direction& dir);

   /*
   If the main character moves, his AABB is used to find out which tiles he is
   standing over. His direction of motion is calculated and used to consider a
   subset of these tiles for possible collisions. The tiles that have an AABB
   define a subset of this subset, and it is each of these tiles' AABBs that is
   compared to the main character's AABB for a possible collision with a call to
   "checkForCollision" that's defined in the derived Room classes.
   */
	virtual void findTilesStandingOver();

	virtual MainCharacter* const getMainCharacterPtr();

   // Set to true when the room is in translating mode (in or out). This flag
   // prevents unwanted updates from happening while the room is moving in or
   // out of the screen.
	void setTranslating(const bool& trans);
protected:
	virtual void draw(sf::RenderTarget& rt, sf::RenderStates states) const
		override;

   // Handy utility function that produces a unit vector given an enum
   // direction.
	sf::Vector2f getUnitVector(Direction& dir);
protected:
	MainCharacter* mcPointer;
	const std::string fileName;
	const std::string roomName;
	const int tileWidth;
	const int tileHeight;
   bool firstRoom;
   bool roomLoaded;
	bool translating;
   BoundaryHit boundaryHit;

   // Array of vertices used to identify tiles in the texture to draw to the
   // screen.
	sf::VertexArray vertexArray;
	sf::VertexArray vertexArrayLayerTwo;

	sf::Texture texture;

   // The size of room translations when transitioning to a different room. E.g.
   // a value of 4 means shift 4 pixels per translation. This is static_asserted
   // to be evenly divisible into the window width and height so the new room
   // translating in fits perfectly into the window.
	static constexpr unsigned int transMag = 4;
	static_assert(Constants::WINDOW_WIDTH_PIXELS % transMag == 0,
		"Window width not evenly divisible by room transition "
		"magnitude");
	static_assert(Constants::WINDOW_HEIGHT_PIXELS % transMag == 0,
		"Window height not evenly divisible by room transition "
		"magnitude");
};