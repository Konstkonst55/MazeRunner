#pragma once

#ifndef CELL_H
#define CELL_H

#include "Point.h"
#include "WallStates.h"
#include "CellType.h"

namespace mg {
	/// <summary>
	///  ласс дл€ работы с €чейкой лабиринта
	/// <para> Point position - позици€ €чейки </para>
	/// <para> WallStates walls - состо€ни€ всех стен €чейки </para>
	/// <para> CellType type - тип €чейки </para>
	/// <para> bool visited - посещена или нет </para>
	/// </summary>
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

		const Point& GetPosition() const;
		const WallStates& GetWalls() const;
		const CellType& GetType() const;
		const bool IsVisited() const;
		void SetPosition(Point);
		void SetWalls(WallStates);
		void SetWallState(int, WallState);
		void SetType(CellType);
		void SetVisitedState(bool);

		void Print();
	};
}

#endif // CELL_H