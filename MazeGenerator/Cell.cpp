#include "cell.h"
#include <format>

#pragma region CellConstructor

mg::Cell::Cell(data::Point position, data::WallStates walls, data::CellType type, bool visited)
	: _position(position), _walls(walls), _type(type), _visited(visited) { }

#pragma endregion

#pragma region CellOperators

const bool mg::Cell::operator==(const mg::Cell& cell) const {
	return _position == cell._position
		&& _walls == cell._walls
		&& _type == cell._type
		&& _visited == cell._visited;
}

#pragma endregion

#pragma region CellGetSet

const mg::data::Point& mg::Cell::GetPosition() const {
	return _position;
}

const mg::data::WallStates& mg::Cell::GetWalls() const {
	return _walls;
}

const mg::data::CellType& mg::Cell::GetType() const {
	return _type;
}

bool mg::Cell::IsVisited() const {
	return _visited;
}

void mg::Cell::SetPosition(const data::Point& point) {
	_position = point;
}

void mg::Cell::SetPosition(int x, int y) {
	_position = data::Point(x, y);
}

void mg::Cell::SetWalls(const data::WallStates& walls) {
	_walls = walls;
}

/// <summary>
/// Устновка состояния стены по ее id
/// <para>(0 - top, 1 - right, 2 - bottom, 3 - left)</para> 
/// </summary>
/// <param name="id">Идентификатор стены</param>
/// <param name="state">Устанавливаемое состояние</param>
void mg::Cell::SetWallState(short id, const data::WallState& state) {
 	data::WallState* walls[] = { &_walls.top, &_walls.right, &_walls.bottom, &_walls.left };

	if (id >= 0 && id < 4) {
		*walls[id] = state;
	}
}

void mg::Cell::SetType(const data::CellType& type) {
	_type = type;
}

void mg::Cell::SetVisitedState(bool visited) {
	_visited = visited;
}

#pragma endregion

#pragma region CellLogic

/// <summary>
/// Возвращает строку в формате [walls: ( {}; {}; {}; {} )], [visited: {}], [type: {}], [position: ( {}; {} )]
/// </summary>
const std::string mg::Cell::ToString() const {
	return std::format(
		"[walls: ( {}; {}; {}; {} )], [visited: {}], [type: {}], [position: ( {}; {} )]",
		static_cast<int>(_walls.top),
		static_cast<int>(_walls.right),
		static_cast<int>(_walls.bottom),
		static_cast<int>(_walls.left),
		_visited ? 1 : 0,
		static_cast<int>(_type),
		_position.x,
		_position.y
	);
}

#pragma endregion