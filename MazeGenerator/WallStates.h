#pragma once

#ifndef WALL_STATES_H
#define WALL_STATES_H

#include "WallState.h"

struct WallStates {
	WallState top = Open;		// 0
	WallState right = Open;		// 1
	WallState bottom = Open;	// 2
	WallState left = Open;		// 3

	WallStates() : top(Open), right(Open), bottom(Open), left(Open) { }
	WallStates(WallState _top, WallState _right, WallState _bottom, WallState _left)
		: top(_top), right(_right), bottom(_bottom), left(_left) { }
};

#endif // WALL_STATES_H