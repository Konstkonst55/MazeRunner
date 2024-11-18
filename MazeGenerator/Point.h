#pragma once

#ifndef POINT_H
#define POINT_H

namespace mg::data {
	/// <summary>
	/// Точка на плоскости
	/// <para> int x </para>
	/// <para> int y </para>
	/// </summary>
	struct Point {
		int x;
		int y;

		Point(int x = 0, int y = 0);
		~Point() = default;

		const bool operator==(const Point& point) const;
	};
}

#endif // POINT_H