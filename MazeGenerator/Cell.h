#pragma once

#ifndef CELL_H
#define CELL_H

#include <ostream>
#include <iostream>

#include "point.h"
#include "wall_states.h"
#include "cell_type.h"

namespace mg {
	/// <summary>
	///  ласс дл€ работы с €чейкой лабиринта
	/// <para> WallStates walls - состо€ни€ всех стен €чейки </para>
	/// <para> bool visited - посещена или нет </para>
	/// </summary>
	class Cell {
	private:
		data::WallStates _walls;
		bool _visited = false;

	public:
		Cell(data::WallStates = data::WallStates(), bool visited = false);
		~Cell() = default;

		const bool operator==(const Cell&) const;

		const data::WallStates& GetWalls() const;
		bool IsVisited() const;
		void SetWalls(const data::WallStates& walls);
		void SetWallState(short id, const data::WallState& state);
		void SetVisitedState(bool visited);

		const std::string ToString() const;
	};
}

#endif // CELL_H