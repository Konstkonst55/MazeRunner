#pragma once

#ifndef MAZE_GENERATOR
#define MAZE_GENERATOR

#include <vector>
#include "Cell.h"
#include "MazeSize.h"

namespace mg {
	class MazeGenerator {
	private:
		unsigned int _seed;
		MazeSize _size;

		unsigned int GenerateSeed();

	public:
		MazeGenerator();
		MazeGenerator(unsigned int);
		MazeGenerator(MazeSize);
		MazeGenerator(unsigned int, MazeSize);

		unsigned int GetSeed();
		void SetSeed(unsigned int);
		MazeSize GetSize();
		void SetSize(MazeSize);

		std::vector<std::vector<Cell>> Generate();
	};
}

#endif // MAZE_GENERATOR