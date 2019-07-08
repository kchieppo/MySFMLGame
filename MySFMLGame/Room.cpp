#include "Room.h"

Room::Room(int tileWidth, int tileHeight)
	:
	tileWidth(tileWidth),
	tileHeight(tileHeight)
{
	texture.loadFromFile("Sprites/Environment/ground_tiles.png");
	grassTileIntRect = { 32, 64, tileWidth, tileHeight };
	sprite.setTexture(texture);
	sprite.setTextureRect(grassTileIntRect);
}

void Room::draw(sf::RenderTarget& rt)
{
	float curX = -1.0f * tileWidth;
	float curY = 0;

	while (curX <= rt.getSize().x - grassTileIntRect.width)
	{
		curX += tileWidth;
		sprite.setPosition({ curX, curY });
		rt.draw(sprite);
		if (curX + grassTileIntRect.width > rt.getSize().x)
		{
			curX = -1.0f * tileWidth;
			if (curY + grassTileIntRect.height < rt.getSize().y)
				curY += grassTileIntRect.height;
			else
				break;
		}
	}
}