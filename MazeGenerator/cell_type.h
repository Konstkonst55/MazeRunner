#pragma once

#ifndef CELL_TYPE_H
#define CELL_TYPE_H

namespace mg::data {
	/// <summary>
	/// ѕеречисление типа €чейки
	/// <para> End = 0 - конец </para>
	/// <para> Start = 1 - начало </para>
	/// <para> Default = 2 - обычна€ €чейка </para>
	/// </summary>
	enum CellType {
		Start = 1,
		End = 0,
		Default = 2
	};
}

#endif // CELL_TYPE_H