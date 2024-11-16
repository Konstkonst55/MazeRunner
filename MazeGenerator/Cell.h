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
	/// ����� ��� ������ � ������� ���������
	/// <para> Point position - ������� ������ </para>
	/// <para> WallStates walls - ��������� ���� ���� ������ </para>
	/// <para> CellType type - ��� ������ </para>
	/// <para> bool visited - �������� ��� ��� </para>
	/// </summary>
	class Cell {
	private:
		data::Point _position;
		data::WallStates _walls;
		data::CellType _type = data::CellType::Default;
		bool _visited = false;

	public:
		Cell(data::Point = data::Point(), data::WallStates = data::WallStates(), data::CellType = data::CellType::Default, bool visited = false);

		const bool operator==(const Cell&) const;

		const data::Point& GetPosition() const;
		const data::WallStates& GetWalls() const;
		const data::CellType& GetType() const;
		bool IsVisited() const;
		void SetPosition(const data::Point& point);
		void SetPosition(int x, int y);
		void SetWalls(const data::WallStates& walls);
		void SetWallState(short id, const data::WallState& state);
		void SetType(const data::CellType& type);
		void SetVisitedState(bool visited);

		const std::string ToString() const;
	};
}

#endif // CELL_H