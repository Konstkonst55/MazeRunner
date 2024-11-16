#include "point.h"

#pragma region PointConstructor

mg::data::Point::Point(int x, int y) : x(x), y(y) { }

#pragma endregion

#pragma region PointOperators

const bool mg::data::Point::operator==(const Point& point) const {
	return this->x == point.x && this->y == point.y;
}

#pragma endregion