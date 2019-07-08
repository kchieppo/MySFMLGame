#include "TitleScreen.h"

TitleScreen::TitleScreen()
{
	texture.loadFromFile("Sprites/Title.png");
	sprite.setTexture(texture);
	sprite.setTextureRect({ 0, 0, 218, 40 });
	sprite.setPosition({ 291, 280 });
}

void TitleScreen::draw(sf::RenderTarget& rt)
{
	rt.draw(sprite);
}