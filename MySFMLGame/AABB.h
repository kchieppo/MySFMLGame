#pragma once
#include <SFML/Graphics.hpp>

class AABB {
public:
	AABB(const sf::Vector2f& min, const sf::Vector2f& max);
	void update(const sf::Vector2f& spriteDir);
	void update(const sf::Vector2f&& spriteDir);
	const sf::Vector2f& getMin() const;
	const sf::Vector2f& getMax() const;
	void reset();
private:
	const sf::Vector2f aabbMinStart;
	const sf::Vector2f aabbMaxStart;
	sf::Vector2f aabbMin;
	sf::Vector2f aabbMax;
};