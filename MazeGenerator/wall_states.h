#pragma once

#ifndef WALL_STATES_H
#define WALL_STATES_H

#include "wall_state.h"

namespace mg::data {
	/// <summary>
	/// ��������� ���� ����
	/// <para> 0: WallState top - ������� ����� </para>
	/// <para> 1: WallState right - ������ ����� </para>
	/// <para> 2: WallState bottom - ������ ����� </para>
	/// <para> 3: WallState left - ����� ����� </para>
	/// <para> �� ��������� ��� ����� ������� </para>
	/// </summary>
	struct WallStates {
		WallState top = WallState::Close;
		WallState right = WallState::Close;
		WallState bottom = WallState::Close;
		WallState left = WallState::Close;

		WallStates(WallState top = WallState::Close, WallState right = WallState::Close, WallState bottom = WallState::Close, WallState left = WallState::Close);

		const bool operator==(const WallStates& walls) const;
	};
}

#endif // WALL_STATES_H