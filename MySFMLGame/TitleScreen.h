#pragma once
#include <SFML/Graphics.hpp>

class TitleScreen
{
public:
	TitleScreen();
	void draw(sf::RenderTarget& rt);
	sf::Sprite sprite;
private:
	sf::Texture texture;
	//sf::Sprite sprite;
};