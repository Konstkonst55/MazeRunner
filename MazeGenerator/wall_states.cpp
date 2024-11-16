#include "wall_states.h"

#pragma region WallStatesConstructor

mg::data::WallStates::WallStates(WallState _top, WallState _right, WallState _bottom, WallState _left)
	: top(_top), right(_right), bottom(_bottom), left(_left) { }

#pragma endregion

#pragma region WallStatesOperators

const bool mg::data::WallStates::operator==(const WallStates& walls) const {
	return this->top == walls.top
		&& this->right == walls.right
		&& this->bottom == walls.bottom
		&& this->left == walls.left;
}

#pragma endregion