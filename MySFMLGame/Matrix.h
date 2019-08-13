#pragma once
#include <array>

// Designed to make 2D std::array initialization easier.
template <class T, size_t ROW, size_t COL>
using Matrix = std::array<std::array<T, COL>, ROW>;
