#pragma once

#ifndef MAZE_GENERATOR_H
#define MAZE_GENERATOR_H

#include <vector>
#include "Cell.h"
#include "MazeSize.h"

namespace mg {
	/// <summary>
	/// Класс для генерации лабиринта
    /// <para> uint seed - сид для генерации </para>
    /// <para> bool useUserSeed = false - использовать пользовательский сид </para>
    /// <para> MazeSize size = MazeSize() - размер лабиринта </para>
    /// <para> vector vector Cell maze - лабиринт </para>
	/// </summary>
	class MazeGenerator {
	private:
		unsigned int _seed;
		bool _useUserSeed = false;
		MazeSize _size = MazeSize();
		std::vector<std::vector<Cell>> _maze;
		mg::Point _start = mg::Point();
		mg::Point _end = mg::Point();

		void MazeInit();
		int FindRoot(std::vector<int>&, int);
		unsigned int GenerateSeed();

	public:
		MazeGenerator();
		MazeGenerator(unsigned int);
		MazeGenerator(MazeSize);
		MazeGenerator(unsigned int, MazeSize);

		const unsigned int GetSeed() const;
		const MazeSize& GetSize() const;
		const std::vector<std::vector<Cell>>& GetMaze() const;
		void SetSeed(unsigned int);
		void SetSize(const MazeSize&S);
		void SetStart(const mg::Point&);
		void SetEnd(const mg::Point&);

		void Generate();
	};
}

#endif // MAZE_GENERATOR_H