#pragma once

#ifndef WALL_STATES_H
#define WALL_STATES_H

#include "WallState.h"

struct WallStates {
	WallState top = Close;			// 0
	WallState right = Close;		// 1
	WallState bottom = Close;		// 2
	WallState left = Close;			// 3

	WallStates() : top(Close), right(Close), bottom(Close), left(Close) { }
	WallStates(WallState _top, WallState _right, WallState _bottom, WallState _left)
		: top(_top), right(_right), bottom(_bottom), left(_left) { }
};

#endif // WALL_STATES_H