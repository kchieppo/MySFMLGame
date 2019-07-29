#include "TitleScreen.h"
#include "Constants.h"

TitleScreen::TitleScreen()
{
	texture.loadFromFile("Sprites/Title.png");
	sprite.setTexture(texture);
	sprite.setTextureRect({ 0, 0, 218, 40 });
	sprite.setPosition({
		static_cast<float>(Constants::WINDOW_WIDTH_PIXELS / 2
			- sprite.getTextureRect().width / 2),
		static_cast<float>(Constants::WINDOW_HEIGHT_PIXELS / 2
			- sprite.getTextureRect().height / 2)
	});
	
}

void TitleScreen::draw(sf::RenderTarget& rt)
{
	rt.draw(sprite);
}