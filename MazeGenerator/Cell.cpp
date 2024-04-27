
#include "Cell.h"
#include <iostream>
#include <format>

Cell::Cell()
	: Cell(Point(0, 0)) {}

Cell::Cell(Point position)
	: Cell(position, WallStates()) { }

Cell::Cell(Point position, WallStates walls)
	: Cell(position, walls, false) { }

Cell::Cell(Point position, WallStates walls, bool visited)
	: Cell(position, walls, Default, visited) { }

Cell::Cell(Point position, WallStates walls, CellType type, bool visited)
	: _position(position), _walls(walls), _type(type), _visited(visited) { }

Point& Cell::GetPosition() {
	return _position;
}

void Cell::SetPosition(Point point) {
	_position = point;
}

WallStates& Cell::GetWalls() {
	return _walls;
}

void Cell::SetWalls(WallStates walls) {
	_walls = walls;
}

void Cell::SetWallState(int id, WallState state) {
	switch (id)
	{
		case 0: _walls.top = state; break;
		case 1: _walls.right = state; break;
		case 2: _walls.bottom = state; break;
		case 3: _walls.left = state; break;
		default:
			break;
	}
}

void Cell::SetType(CellType type) {
	_type = type;
}

CellType& Cell::GetType(){
	return _type;
}

bool Cell::IsVisited() {
	return _visited;
}

void Cell::SetVisitedState(bool visitedState) {
	_visited = visitedState;
}

void Cell::Print() {
	std::cout << std::format("t: {} r: {} b: {} l: {}",
		(int)_walls.top, (int)_walls.right, (int)_walls.bottom, (int)_walls.left) 
		<< std::endl;
}
