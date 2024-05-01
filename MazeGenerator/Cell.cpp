
#include "Cell.h"
#include <iostream>
#include <format>

#pragma region CellConstructor

mg::Cell::Cell()
	: Cell(Point(0, 0)) { }

mg::Cell::Cell(Point position)
	: Cell(position, WallStates()) { }

mg::Cell::Cell(Point position, WallStates walls)
	: Cell(position, walls, false) { }

mg::Cell::Cell(Point position, WallStates walls, bool visited)
	: Cell(position, walls, Default, visited) { }

mg::Cell::Cell(Point position, WallStates walls, CellType type, bool visited)
	: _position(position), _walls(walls), _type(type), _visited(visited) { }

#pragma endregion

#pragma region CellGetSet

const mg::Point& mg::Cell::GetPosition() const {
	return _position;
}

const mg::WallStates& mg::Cell::GetWalls() const {
	return _walls;
}

const mg::CellType& mg::Cell::GetType() const {
	return _type;
}

const bool mg::Cell::IsVisited() const {
	return _visited;
}

void mg::Cell::SetPosition(Point point) {
	_position = point;
}

void mg::Cell::SetWalls(WallStates walls) {
	_walls = walls;
}

void mg::Cell::SetWallState(int id, WallState state) {
	WallState* walls[] = { &_walls.top, &_walls.right, &_walls.bottom, &_walls.left };

	if (id >= 0 && id < 4) {
		*walls[id] = state;
	}
}

void mg::Cell::SetType(CellType type) {
	_type = type;
}

void mg::Cell::SetVisitedState(bool visitedState) {
	_visited = visitedState;
}

#pragma endregion

#pragma region CellLogic

/// <summary>
/// ѕечать €чейки в консоль в формате t: _ r: _ b: _ l: _ v: _ tp: _ p: [ _ ; _ ]
/// </summary>
void mg::Cell::Print() {
	std::cout << std::format("t: {} r: {} b: {} l: {} v: {} tp: {} p: [ {} ; {} ]",
		(int)_walls.top, (int)_walls.right, (int)_walls.bottom,
		(int)_walls.left, _visited ? 1 : 0, (int)_type,
		_position.x, _position.y)
		<< std::endl;
}

#pragma endregion