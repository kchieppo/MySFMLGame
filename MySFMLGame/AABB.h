#pragma once
#include <SFML/Graphics.hpp>

class AABB {
public:
	AABB(const sf::Vector2f& min, const sf::Vector2f& max);
	void update(const sf::Vector2f& spriteDir);
	void update(const sf::Vector2f&& spriteDir);
	const sf::Vector2f& getPosition() const;
	const sf::Vector2f& getMin() const;
	const sf::Vector2f& getMax() const;
private:
	sf::Vector2f aabbPos;
	sf::Vector2f aabbMin;
	sf::Vector2f aabbMax;
	sf::Vector2f aabbDir;
};