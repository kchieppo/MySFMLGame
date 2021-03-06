#pragma once
#include <SFML/Graphics.hpp>
#include <type_traits>

/*
Axis-aligned bounding box. Instance(s) are given to characters and tiles so
collisions between them can be detected.                                       
                                                                               
Typically, tiles are given an AABB of typeTypically, tiles are given an AABB of
sf::Vector2i (integer) so their dimensions have a one-to-one correspondence	 
with the underlying pixel array to make room design simple. Whereas, characters
are given one of type sf::Vector2f (float) to give them more fluidity of motion.
*/
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
		prevAabbMin{ 0, 0 },
		prevAabbMax{ 0, 0 },
		aabbMin{ 0, 0 },
		aabbMax{ 0, 0 }
	{
	}

	AABB(const T& min, const T& max)
		:
		aabbMinStart{ min },
		aabbMaxStart{ max },
		prevAabbMin{ min },
		prevAabbMax{ max },
		aabbMin{ min },
		aabbMax{ max }
	{
	}

   AABB(const AABB& aabb)
      :
      aabbMinStart{ aabb.aabbMinStart },
      aabbMaxStart{ aabb.aabbMaxStart },
      prevAabbMin{ aabb.prevAabbMin },
      prevAabbMax{ aabb.prevAabbMax },
		aabbMin{ aabb.aabbMin },
		aabbMax{ aabb.aabbMax }
   {
   }

   AABB<T>& operator=(const AABB<T>& aabb)
   {
      aabbMinStart = aabb.aabbMinStart;
      aabbMaxStart = aabb.aabbMaxStart;
      prevAabbMin = aabb.prevAabbMin;
      prevAabbMax = aabb.prevAabbMax;
		aabbMin = aabb.aabbMin;
		aabbMax = aabb.aabbMax;
      return *this;
   }

   // Updates the AABB position in conjunction with character/tile movement.
   // spriteDist is 2D displacement of the character/tile.
	void update(const T& spriteDist)
	{
		storeOldAabb();
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

	const T& getPrevMin() const
	{
		return prevAabbMin;
	}

	const T& getPrevMax() const
	{
		return prevAabbMax;
	}

	void setMinMax(const T& min, const T& max)
	{
		storeOldAabb();
		aabbMin = min;
		aabbMax = max;
	}
   // Resets the AABB position to its starting position.
	void reset()
	{
		prevAabbMin = aabbMinStart;
		prevAabbMax = aabbMaxStart;
		aabbMin = aabbMinStart;
		aabbMax = aabbMaxStart;
	}
private:

	void storeOldAabb()
	{
		prevAabbMin = aabbMin;
		prevAabbMax = aabbMax;
	}

	// The starting x, y coordinate of the bottom-left corner of the AABB.
   // Needed in case we want to "reset" a character or tile to its original
   // configuration. This should never be changed.
	T aabbMinStart;
   // The starting x, y coordinate of the top-right corner of the AABB. Needed
   // in case we want to "reset" a character or tile to its original
   // configuration. This should never be changed.
	T aabbMaxStart;

	// Previous AABB kept for collision detection with rays
   // The x, y coordinate of the bottom-left corner of the old AABB.
	T prevAabbMin;
   // The x, y coordinate of the top-right corner of the old AABB.
	T prevAabbMax;

	// The x, y coordinate of the bottom-left corner of the AABB.
	T aabbMin;
	// The x, y coordinate of the top-right corner of the AABB.
	T aabbMax;
};