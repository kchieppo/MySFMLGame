#include "Room.h"

Room::Room(const std::string& fileName, const std::string& roomName,
	const unsigned int tileWidth, const unsigned int tileHeight)
	:
	fileName{ fileName },
	roomName{ roomName },
	tileWidth{ tileWidth },
	tileHeight{ tileHeight },
	roomLoaded{ false }
{
}

const bool& Room::isLoaded() const
{
	return roomLoaded;
}

bool Room::load()
{
	return false;
}

void Room::update(const float& dt)
{
	return;
}

void Room::reset()
{
	return;
}


void Room::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (!roomLoaded)
	{
		std::cerr << "Room \"" << roomName << "\" could not be loaded."
			<< std::endl;
		return;
	}
	// apply the transform
	states.transform *= getTransform();

	// apply the tileset texture
	states.texture = &texture;

	// draw the vertex array
	target.draw(vertexArray, states);
}
