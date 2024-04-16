#pragma once

#ifndef POINT_H
#define POINT_H

struct Point {
	int x;
	int y;
	Point(int _x, int _y) : x(_x), y(_y) { }
};

#endif // POINT_H