#include "CollisionMap.h"

CollisionMap::CollisionMap()
{
	for (auto& row : bitMap)
	{
		for (auto& bit : row)
		{
			bit = false;
		}
	}
	bitMap[299][299] = true;
}