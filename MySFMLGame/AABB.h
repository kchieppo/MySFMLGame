#pragma once
#include <SFML/Graphics.hpp>
#include <type_traits>

template<typename T>
class AABB {
	static_assert(std::is_same<T, sf::Vector2f>::value
		|| std::is_same<T, sf::Vector2i>::value, "AABB type must be "
		"sf::Vector2f or sf::Vector2i.");
public:
	AABB()
		:
		aabbMinStart{ 0, 0 },
		aabbMaxStart{ 0, 0 },
		aabbMin{ 0, 0 },
		aabbMax{ 0, 0 }
	{
	}

	AABB(const T& min, const T& max)
		:
		aabbMinStart{ min },
		aabbMaxStart{ max },
		aabbMin{ min },
		aabbMax{ max }
	{
	}

	void update(const T& spriteDist)
	{
		aabbMin += spriteDist;
		aabbMax += spriteDist;
	}

	const T& getMin() const
	{
		return aabbMin;
	}

	const T& getMax() const
	{
		return aabbMax;
	}

	void setMinMax(const T& min, const T& max)
	{
		aabbMin = min;
		aabbMax = max;
	}

	void reset()
	{
		aabbMin = aabbMinStart;
		aabbMax = aabbMaxStart;
	}
private:
	T aabbMinStart;
	T aabbMaxStart;
	T aabbMin;
	T aabbMax;
};