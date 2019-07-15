#pragma once
#include <array>

class CollisionMap {
public:
	CollisionMap();
private:
	std::array<std::array<bool, 600>, 800> bitMap;
};