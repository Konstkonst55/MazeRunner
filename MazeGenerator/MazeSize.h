#pragma once

#ifndef MAZE_SIZE_H
#define MAZE_SIZE_H

namespace mg {
	struct MazeSize {
		unsigned int width;
		unsigned int height;
		MazeSize() : width(25), height(25) { }
		MazeSize(unsigned int _width, unsigned int _height) : width(_width), height(_height) { }
	};
}

#endif // MAZE_SIZE_H