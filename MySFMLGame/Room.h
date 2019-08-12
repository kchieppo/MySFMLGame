#pragma once
#include "Constants.h"
#include "Direction.h"
#include "MainCharacter.h"
#include <array>
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

class Room : public sf::Drawable, public sf::Transformable
{
public:
	Room(const std::string& fileName, const std::string& roomName,
      const int tileWidth, const int tileHeight, const bool& firstRoom);
	const bool& isLoaded() const;
	virtual void load(MainCharacter* mcP);
	virtual void update(const float& dt);
	virtual void reset();
	virtual void translateIn(Direction& dir);
	virtual void translateOut(Direction& dir);
	virtual void findTilesStandingOver();
	virtual MainCharacter* const getMainCharacterPtr();
	void setTranslating(const bool& trans);
protected:
	virtual void draw(sf::RenderTarget& rt, sf::RenderStates states) const
		override;
	sf::Vector2f getUnitVector(Direction& dir);
protected:
	MainCharacter* mcPointer;
	const std::string fileName;
	const std::string roomName;
	const int tileWidth;
	const int tileHeight;
	bool roomLoaded;
	bool firstRoom;
	bool translating;
	sf::VertexArray vertexArray;
	sf::VertexArray vertexArrayLayerTwo;
	sf::Texture texture;
	sf::Texture textureMasked;
	static constexpr unsigned int transMag = 4;
	static_assert(Constants::WINDOW_WIDTH_PIXELS % transMag == 0,
		"Window width not evenly divisible by room transition "
		"magnitude");
	static_assert(Constants::WINDOW_HEIGHT_PIXELS % transMag == 0,
		"Window height not evenly divisible by room transition "
		"magnitude");
};