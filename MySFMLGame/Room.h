#pragma once
#include "Constants.h"
#include "Direction.h"
#include <array>
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>

class Room : public sf::Drawable, public sf::Transformable
{
public:
	Room(const std::string& fileName, const std::string& roomName,
		const int tileWidth, const int tileHeight, bool&& firstRoom);
	const bool& isLoaded() const;
	virtual bool load();
	virtual void update(const float& dt);
	virtual void reset();
	virtual void translateIn(Direction& dir);
	virtual void translateOut(Direction& dir);
	void setTranslatingIn(bool&& transIn);
protected:
	virtual void draw(sf::RenderTarget& rt, sf::RenderStates states) const override;
	sf::Vector2f&& getUnitVector(Direction& dir);
protected:
	const std::string fileName;
	const std::string roomName;
	const int tileWidth;
	const int tileHeight;
	bool roomLoaded;
	bool firstRoom;
	bool translatingIn;
	sf::VertexArray vertexArray;
	sf::Texture texture;
	static constexpr unsigned int transMag = 4;
	static_assert(Constants::WINDOW_WIDTH_PIXELS % transMag == 0,
		"Window width not evenly divisible by room transition "
		"magnitude");
	static_assert(Constants::WINDOW_HEIGHT_PIXELS % transMag == 0,
		"Window height not evenly divisible by room transition "
		"magnitude");
};