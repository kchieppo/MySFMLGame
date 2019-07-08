#pragma once
#include <SFML/Graphics.hpp>

class Room
{
public:
	Room(int tileWidth, int tileHeight);
	void draw(sf::RenderTarget& rt);
private:
	int tileWidth;
	int tileHeight;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::IntRect grassTileIntRect;
};