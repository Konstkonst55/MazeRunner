#pragma once

#ifndef MAZE_GENERATOR_H
#define MAZE_GENERATOR_H

#include <vector>
#include "cell.h"
#include "maze_size.h"
#include "maze.h"

namespace mg::gen {
	/// <summary>
	/// ����� ��� ��������� ���������
    /// <para> uint seed - ��� ��� ��������� </para>
    /// <para> bool useUserSeed = false - ������������ ���������������� ��� </para>
    /// <para> Maze maze - �������� </para>
	/// </summary>
	class MazeGenerator {
	protected:
		Maze _maze;
		unsigned int _seed;
		bool _useUserSeed = false;

		virtual unsigned int GenerateSeed();

	public:
		MazeGenerator();
		MazeGenerator(unsigned int seed);
		MazeGenerator(const data::MazeSize& size);
		MazeGenerator(unsigned int seed, const data::MazeSize& size);
		~MazeGenerator() = default;

		const unsigned int GetSeed() const;
		const Maze& GetMaze() const;
		Maze& GetMaze();
		void SetSeed(unsigned int seed);

		virtual void Generate() = 0;
	};
}

#endif // MAZE_GENERATOR_H