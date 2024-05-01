#pragma once

#ifndef POINT_H
#define POINT_H

namespace mg {
	/// <summary>
	/// Точка на плоскости
	/// <para> int x </para>
	/// <para> int y </para>
	/// </summary>
	struct Point {
		int x;
		int y;

		Point() : x(0), y(0) { }
		Point(int x, int y) : x(x), y(y) { }

		const bool operator==(const Point& point) const {
			return this->x == point.x && this->y == point.y;
		}
	};
}

#endif // POINT_H