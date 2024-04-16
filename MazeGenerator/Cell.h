#pragma once

#ifndef CELL_H
#define CELL_H

#include "Point.h"
#include "WallStates.h"

class Cell {
private:
	Point _position;
	WallStates _walls;
	bool _visited = false;

public:
	Cell(Point);
	Cell(Point, WallStates);
	Cell(Point, WallStates, bool);

	Point GetPosition();
	void SetPosition(Point);
	WallStates GetWalls();
	void SetWalls(WallStates);
	bool IsVisited();
	void SetVisitedState(bool);
};

#endif // CELL_H