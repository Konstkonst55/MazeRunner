#pragma once

#ifndef WALL_STATES_H
#define WALL_STATES_H

#include "WallState.h"

namespace mg {
	/// <summary>
	/// ��������� ���� ����
	/// <para> 0: WallState top - ������� ����� </para>
	/// <para> 1: WallState right - ������ ����� </para>
	/// <para> 2: WallState bottom - ������ ����� </para>
	/// <para> 3: WallState left - ����� ����� </para>
	/// <para> �� ��������� ��� ����� ������� </para>
	/// </summary>
	struct WallStates {
		WallState top = Close;
		WallState right = Close;
		WallState bottom = Close;
		WallState left = Close;

		WallStates() 
			: top(Close), right(Close), bottom(Close), left(Close) { }
		WallStates(WallState _top, WallState _right, WallState _bottom, WallState _left)
			: top(_top), right(_right), bottom(_bottom), left(_left) { }

		const bool operator==(const WallStates& walls) const {
			return this->top == walls.top
				&& this->right == walls.right
				&& this->bottom == walls.bottom
				&& this->left == walls.left;
		}
	};
}

#endif // WALL_STATES_H