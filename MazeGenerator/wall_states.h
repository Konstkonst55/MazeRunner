#pragma once

#ifndef WALL_STATES_H
#define WALL_STATES_H

#include "wall_state.h"

namespace mg::data {
	/// <summary>
	/// —осто€ни€ всех стен
	/// <para> 0: WallState top - верхн€€ стена </para>
	/// <para> 1: WallState right - права€ стена </para>
	/// <para> 2: WallState bottom - нижн€€ стена </para>
	/// <para> 3: WallState left - лева€ стена </para>
	/// <para> ѕо умолчанию все стены закрыты </para>
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