#include "Room.h"

Room::Room(const std::string& fileName, const std::string& roomName,
	const int& tileWidth, const int& tileHeight, const bool& firstRoom)
	:
	mcPointer{ nullptr },
	fileName{ fileName },
	roomName{ roomName },
	tileWidth{ tileWidth },
	tileHeight{ tileHeight },
	roomLoaded{ false },
	firstRoom{ firstRoom },
	translating{ false }
{
}

const bool& Room::isLoaded() const
{
	return roomLoaded;
}

void Room::load(MainCharacter* mcP)
{
	mcPointer = mcP;
}

void Room::update(const float& dt)
{
	return;
}

void Room::reset()
{
	return;
}

void Room::translateIn(Direction& dir)
{
	return;
}

void Room::translateOut(Direction& dir)
{
	return;
}

void Room::findTilesStandingOver()
{
	return;
}

MainCharacter* const Room::getMainCharacterPtr()
{
	return mcPointer;
}

void Room::setTranslating(const bool& trans)
{
	translating = trans;
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

	if (vertexArrayLayerTwo.getVertexCount() > 0)
		target.draw(vertexArrayLayerTwo, states);
}

sf::Vector2f Room::getUnitVector(Direction& dir)
{
	switch (dir)
	{
	case Direction::Up:
		return sf::Vector2f({ 0.0f, -1.0f });
	case Direction::Down:
		return sf::Vector2f({ 0.0f, 1.0f });
	case Direction::Left:
		return sf::Vector2f({ -1.0f, 0.0f });
	case Direction::Right:
		return sf::Vector2f({ 1.0f, 0.0f });
	case Direction::None:
		return sf::Vector2f({ 0.0f, 0.0f });
	default:
		return sf::Vector2f({ 0.0f, 0.0f });
	}
}
