#pragma once
#include "Constants.h"
#include <array>
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>

class Room : public sf::Drawable, public sf::Transformable
{
public:
	Room(const std::string& fileName, const std::string& roomName,
		const unsigned int tileWidth, const unsigned int tileHeight);
	const bool& isLoaded() const;
	virtual bool load();
protected:
	void draw(sf::RenderTarget& rt, sf::RenderStates states) const override;
protected:
	const std::string fileName;
	const std::string roomName;
	const unsigned int tileWidth;
	const unsigned int tileHeight;
	bool roomLoaded;
	sf::VertexArray vertexArray;
	sf::Texture texture;
private:
	sf::Sprite sprite;
	sf::IntRect grassTileIntRect;
};