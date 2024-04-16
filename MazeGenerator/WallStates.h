#pragma once

#ifndef WALL_STATES_H
#define WALL_STATES_H

#include "WallState.h"

struct WallStates {
	WallState top = Close;
	WallState right = Close;
	WallState bottom = Close;
	WallState left = Close;

	WallStates() : top(Close), right(Close), bottom(Close), left(Close) { }
	WallStates(WallState _top, WallState _right, WallState _bottom, WallState _left)
		: top(_top), right(_right), bottom(_bottom), left(_left) { }
};

#endif // WALL_STATES_H