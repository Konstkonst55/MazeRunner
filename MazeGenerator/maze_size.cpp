#include "maze_size.h"

#pragma region MazeSizeConstructor

mg::data::MazeSize::MazeSize(size_t width, size_t height) : width(width), height(height) { }

#pragma endregion

#pragma region MazeSizeOperators

const bool mg::data::MazeSize::operator==(const MazeSize& size) const {
	return this->width == size.width && this->height == size.height;
}

#pragma endregion
