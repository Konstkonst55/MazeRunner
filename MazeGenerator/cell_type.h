#pragma once

#ifndef CELL_TYPE_H
#define CELL_TYPE_H

namespace mg::data {
	/// <summary>
	/// ������������ ���� ������
	/// <para> End = 0 - ����� </para>
	/// <para> Start = 1 - ������ </para>
	/// <para> Default = 2 - ������� ������ </para>
	/// </summary>
	enum CellType {
		Start = 1,
		End = 0,
		Default = 2
	};
}

#endif // CELL_TYPE_H