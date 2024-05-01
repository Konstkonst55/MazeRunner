#pragma once

#ifndef MAZE_GENERATOR_H
#define MAZE_GENERATOR_H

#include <vector>
#include "Cell.h"
#include "MazeSize.h"

namespace mg {
	class MazeGenerator {
	private:
		unsigned int _seed;
		MazeSize _size;
		std::vector<std::vector<Cell>> _maze;

		void MazeInit();

	public:
		MazeGenerator();
		MazeGenerator(unsigned int);
		MazeGenerator(MazeSize);
		MazeGenerator(unsigned int, MazeSize);

		unsigned int GetSeed();
		void SetSeed(unsigned int);
		MazeSize GetSize();
		void SetSize(MazeSize);
		std::vector<std::vector<Cell>>& GetMaze();

		void Generate();
		unsigned int GenerateSeed();
		int FindRoot(std::vector<int>&, int);
	};
}

#endif // MAZE_GENERATOR_H