#pragma once

#ifndef MAZE_SIZE
#define MAZE_SIZE

struct MazeSize {
	unsigned int width;
	unsigned int height;
	MazeSize() : width(25), height(25) { }
	MazeSize(unsigned int _width, unsigned int _height) : width(_width), height(_height) { }
};

#endif // MAZE_SIZE