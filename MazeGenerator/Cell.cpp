
#include "Cell.h"
#include <iostream>

Cell::Cell()
	: Cell(Point(0, 0)) {}

Cell::Cell(Point point) 
	: Cell(point, WallStates()) { }

Cell::Cell(Point point, WallStates walls) 
	: Cell(point, walls, false) { }

Cell::Cell(Point position, WallStates walls, bool visited)
	: _position(position), _walls(walls), _visited(visited) { }

Point Cell::GetPosition() {
	return _position;
}

void Cell::SetPosition(Point point) {
	_position = point;
}

WallStates Cell::GetWalls() {
	return _walls;
}

void Cell::SetWalls(WallStates walls) {
	_walls = walls;
}

bool Cell::IsVisited() {
	return _visited;
}

void Cell::SetVisitedState(bool visitedState) {
	_visited = visitedState;
}

void Cell::Print() {
	std::cout << "cell";
}
