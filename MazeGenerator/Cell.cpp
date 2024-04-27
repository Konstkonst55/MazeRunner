
#include "Cell.h"
#include <iostream>
#include <format>

mg::Cell::Cell()
	: Cell(Point(0, 0)) {}

mg::Cell::Cell(Point position)
	: Cell(position, WallStates()) { }

mg::Cell::Cell(Point position, WallStates walls)
	: Cell(position, walls, false) { }

mg::Cell::Cell(Point position, WallStates walls, bool visited)
	: Cell(position, walls, Default, visited) { }

mg::Cell::Cell(Point position, WallStates walls, CellType type, bool visited)
	: _position(position), _walls(walls), _type(type), _visited(visited) { }

mg::Point& mg::Cell::GetPosition() {
	return _position;
}

void mg::Cell::SetPosition(Point point) {
	_position = point;
}

mg::WallStates& mg::Cell::GetWalls() {
	return _walls;
}

void mg::Cell::SetWalls(WallStates walls) {
	_walls = walls;
}

void mg::Cell::SetWallState(int id, WallState state) {
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

void mg::Cell::SetType(CellType type) {
	_type = type;
}

mg::CellType& mg::Cell::GetType(){
	return _type;
}

bool mg::Cell::IsVisited() {
	return _visited;
}

void mg::Cell::SetVisitedState(bool visitedState) {
	_visited = visitedState;
}

void mg::Cell::Print() {
	std::cout << std::format("t: {} r: {} b: {} l: {}",
		(int)_walls.top, (int)_walls.right, (int)_walls.bottom, (int)_walls.left) 
		<< std::endl;
}
