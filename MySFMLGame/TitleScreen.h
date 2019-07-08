#pragma once
#include <SFML/Graphics.hpp>

class TitleScreen
{
public:
	TitleScreen();
	void draw(sf::RenderTarget& rt);
private:
	sf::Texture texture;
	sf::Sprite sprite;
};