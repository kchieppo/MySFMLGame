#pragma once
#include <SFML/Graphics.hpp>

/*
Simple class containing the title screen texture.
*/
class TitleScreen
{
public:
	TitleScreen();
	void draw(sf::RenderTarget& rt);
private:
	sf::Texture texture;
	sf::Sprite sprite;
};