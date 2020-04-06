#include "MainCharacter.h"
#include <cmath>

MainCharacter::MainCharacter(const sf::Vector2f& pos)
	:
	Character(pos),
	positionChanged{ false },
	speed{ 100.0f },
   animations
   {{
      MainCharacterAnimation("MainCharacterWalkingUp",
      "Sprites/Characters/george.png", 106, 4, 0.2f),
      MainCharacterAnimation("MainCharacterWalkingDown",
      "Sprites/Characters/george.png", 10, 4, 0.2f),
      MainCharacterAnimation("MainCharacterWalkingLeft",
      "Sprites/Characters/george.png", 56, 4, 0.2f),
      MainCharacterAnimation("MainCharacterWalkingRight",
      "Sprites/Characters/george.png", 155, 4, 0.2f),
   }},
	curAnimation{ AnimationIndex::WalkingDown },
	prevAnimation{ AnimationIndex::WalkingDown },
	aabb{ {pos.x + 3.0f, pos.y + 32.0f},
		{pos.x + 25.0f, pos.y + 23.0f} },
	drawAabb{ true }
{
	sprite.setTextureRect(sf::IntRect(8, 8, 30, 32));

	if (drawAabb)
	{
		aabbForDrawing.setPrimitiveType(sf::LineStrip);
		aabbForDrawing.resize(5);
		aabbForDrawing[0] = sf::Vertex({ pos.x + 3.0f, pos.y + 23.0f });
		aabbForDrawing[1] = sf::Vertex({ pos.x + 25.0f, pos.y + 23.0f });
		aabbForDrawing[2] = sf::Vertex({ pos.x + 25.0f, pos.y + 32.0f });
		aabbForDrawing[3] = sf::Vertex({ pos.x + 3.0f, pos.y + 32.0f });
		aabbForDrawing[4] = aabbForDrawing[0];
		for (size_t i = 0; i < aabbForDrawing.getVertexCount(); i++)
			aabbForDrawing[i].color = sf::Color::Red;
	}
}

void MainCharacter::draw(sf::RenderTarget& rt) const
{
	Character::draw(rt);

	if (drawAabb)
	{

		rt.draw(aabbForDrawing);
	}
}

void MainCharacter::setAnimationIndex(const sf::Vector2f& dir)
{
	prevAnimation = curAnimation;
	if (dir.y < 0.0f)
		curAnimation = AnimationIndex::WalkingUp;
	else if (dir.y > 0.0f)
		curAnimation = AnimationIndex::WalkingDown;
	else if (dir.x < 0.0f)
		curAnimation = AnimationIndex::WalkingLeft;
	else if (dir.x > 0.0f)
		curAnimation = AnimationIndex::WalkingRight;
}

void MainCharacter::setVelocity(const sf::Vector2f& dir)
{
	vel = dir * speed;
}

void MainCharacter::update(const float& dt)
{
	if (prevAnimation != curAnimation)
	{
		animations[int(prevAnimation)].reset();
		prevAnimation = curAnimation;
	}

	if (vel.x == 0 && vel.y == 0)
		animations[int(curAnimation)].reset();
	else
	{
		sf::Vector2f spriteDist(vel * dt);
		aabb.update(spriteDist);

		if (drawAabb)
			for (size_t i = 0; i < aabbForDrawing.getVertexCount(); i++)
			{
				aabbForDrawing[i] = sf::Vertex
				(
					aabbForDrawing[i].position + spriteDist
				);
				aabbForDrawing[i].color = sf::Color::Red;
			}

		setPosition(sprite.getPosition() + spriteDist);
		animations[int(curAnimation)].update(dt);
	}
	animations[int(curAnimation)].applyToSprite(sprite);
}

const sf::Vector2f& MainCharacter::getPosition() const
{
	return sprite.getPosition();
}

const sf::Vector2f& MainCharacter::getAabbMin() const
{
	return aabb.getMin();
}

const sf::Vector2f& MainCharacter::getAabbMax() const
{
	return aabb.getMax();
}

void MainCharacter::setPosition(const sf::Vector2f& pos)
{
	sprite.setPosition(pos);
	aabb.setMinMax(
		{ pos.x + 3.0f, pos.y + 32.0f },
		{ pos.x + 25.0f, pos.y + 23.0f }
	);
	if (drawAabb)
	{
		aabbForDrawing[0] = sf::Vertex({ pos.x + 3.0f, pos.y + 23.0f });
		aabbForDrawing[1] = sf::Vertex({ pos.x + 25.0f, pos.y + 23.0f });
		aabbForDrawing[2] = sf::Vertex({ pos.x + 25.0f, pos.y + 32.0f });
		aabbForDrawing[3] = sf::Vertex({ pos.x + 3.0f, pos.y + 32.0f });
		aabbForDrawing[4] = aabbForDrawing[0];
		for (size_t i = 0; i < aabbForDrawing.getVertexCount(); i++)
			aabbForDrawing[i].color = sf::Color::Red;
	}
	positionChanged = true;
}

void MainCharacter::setPositionX(const float& posX)
{
	sprite.setPosition(posX, sprite.getPosition().y);
	aabb.setMinMax(
		{ posX + 3.0f, aabb.getMin().y },
		{ posX + 25.0f, aabb.getMax().y }
	);
	if (drawAabb)
	{
		aabbForDrawing[0].position.x = posX + 3.0f;
		aabbForDrawing[1].position.x = posX + 25.0f;
		aabbForDrawing[2].position.x = posX + 25.0f;
		aabbForDrawing[3].position.x = posX + 3.0f;
		aabbForDrawing[4].position.x = aabbForDrawing[0].position.x;
		for (size_t i = 0; i < aabbForDrawing.getVertexCount(); i++)
			aabbForDrawing[i].color = sf::Color::Red;
	}
	positionChanged = true;
}

void MainCharacter::setPositionY(const float& posY)
{
	sprite.setPosition(sprite.getPosition().x, posY);
	aabb.setMinMax(
		{ aabb.getMin().x, posY + 32.0f },
		{ aabb.getMax().x, posY + 23.0f }
	);
	if (drawAabb)
	{
		aabbForDrawing[0].position.y = posY + 23.0f;
		aabbForDrawing[1].position.y = posY + 23.0f;
		aabbForDrawing[2].position.y = posY + 32.0f;
		aabbForDrawing[3].position.y = posY + 32.0f;
		aabbForDrawing[4].position.y = aabbForDrawing[0].position.y;
		for (size_t i = 0; i < aabbForDrawing.getVertexCount(); i++)
			aabbForDrawing[i].color = sf::Color::Red;
	}
	positionChanged = true;
}

void MainCharacter::moveDistance(const sf::Vector2f& dist)
{
	sprite.setPosition(sprite.getPosition().x + dist.x,
      sprite.getPosition().y + dist.y);
	aabb.setMinMax(
		{ aabb.getMin().x + dist.x, aabb.getMin().y + dist.y },
		{ aabb.getMax().x + dist.x, aabb.getMax().y + dist.y }
	);
	if (drawAabb)
	{
		for (size_t i = 0; i < aabbForDrawing.getVertexCount(); i++)
		{
			aabbForDrawing[i].position += dist;
			aabbForDrawing[i].color = sf::Color::Red;
		}
	}
	positionChanged = true;
}

void MainCharacter::moveDistanceX(const float& distX)
{
	sprite.setPosition(sprite.getPosition().x + distX, sprite.getPosition().y);
	aabb.setMinMax(
		{ aabb.getMin().x + distX, aabb.getMin().y },
		{ aabb.getMax().x + distX, aabb.getMax().y }
	);
	if (drawAabb)
	{
		for (size_t i = 0; i < aabbForDrawing.getVertexCount(); i++)
		{
			aabbForDrawing[i].position.x += distX;
			aabbForDrawing[i].color = sf::Color::Red;
		}
	}
	positionChanged = true;
}

void MainCharacter::moveDistanceY(const float& distY)
{
	sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + distY);
	aabb.setMinMax(
		{ aabb.getMin().x, aabb.getMin().y + distY },
		{ aabb.getMax().x, aabb.getMax().y + distY }
	);
	if (drawAabb)
	{
		for (size_t i = 0; i < aabbForDrawing.getVertexCount(); i++)
		{
			aabbForDrawing[i].position.y += distY;
			aabbForDrawing[i].color = sf::Color::Red;
		}
	}
	positionChanged = true;
}

bool MainCharacter::getPositionChanged() const
{
	return positionChanged;
}

void MainCharacter::setPositionChanged(const bool& posChanged)
{
	positionChanged = posChanged;
}

const int& MainCharacter::getSpriteWidth() const
{
	return MainCharacterAnimation::widthFrame;
}

const int& MainCharacter::getSpriteHeight() const
{
	return MainCharacterAnimation::heightFrame;
}

MainCharacter::MainCharacterAnimation::MainCharacterAnimation(
	std::string&& name, std::string&& fileName, int xFirstFrame,
   int numFrames, float timePerFrame)
	:
	Animation(std::move(name), std::move(fileName), numFrames, timePerFrame,
      false)
{
	createFrames(xFirstFrame, yFirstFrame, xOffset, yOffset);
}

void MainCharacter::MainCharacterAnimation::createFrames( int xFirstFrame,
   int yFirstFrame, int xOffset, int yOffset)
{
	for (int i = 0; i < numFrames; i++)
	{
		frames.emplace_back(xFirstFrame + i * xOffset, yFirstFrame + i * yOffset,
         widthFrame, heightFrame);
	}
}
