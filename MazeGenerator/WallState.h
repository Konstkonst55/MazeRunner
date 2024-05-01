#pragma once

#ifndef WALL_STATE_H
#define WALL_STATE_H

namespace mg {
	/// <summary>
	/// ѕеречисление типа состо€ни€ стены
	/// <para>
	/// Open = 1 - открыта
	/// </para>
	/// <para>
	/// Close = 0 - зыкрыта
	/// </para>
	/// </summary>
	enum WallState {
		Open = 1,
		Close = 0
	};
}

#endif // WALL_STATE_H