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
		Point(int _x, int _y) : x(_x), y(_y) { }
	};
}

#endif // POINT_H