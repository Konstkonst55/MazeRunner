#pragma once

#ifndef CELL_H
#define CELL_H

#include "Point.h"
#include "WallStates.h"
#include "CellType.h"

class Cell {
private:
	Point _position;
	WallStates _walls;
	CellType _type = Default;
	bool _visited = false;

public:
	Cell();
	Cell(Point);
	Cell(Point, WallStates);
	Cell(Point, WallStates, bool);
	Cell(Point, WallStates, CellType, bool);

	Point& GetPosition();
	void SetPosition(Point);
	WallStates& GetWalls();
	void SetWalls(WallStates);
	void SetWallState(int, WallState);
	void SetType(CellType);
	CellType& GetType();
	bool IsVisited();
	void SetVisitedState(bool);

	void Print();
};

#endif // CELL_H