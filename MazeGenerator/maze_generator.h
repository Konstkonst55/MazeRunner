#pragma once

#ifndef MAZE_GENERATOR_H
#define MAZE_GENERATOR_H

#include <vector>
#include "cell.h"
#include "maze_size.h"

namespace mg {
	/// <summary>
	/// ����� ��� ��������� ���������
    /// <para> uint seed - ��� ��� ��������� </para>
    /// <para> bool useUserSeed = false - ������������ ���������������� ��� </para>
    /// <para> MazeSize size = MazeSize() - ������ ��������� </para>
    /// <para> vector vector Cell maze - �������� </para>
	/// </summary>
	class MazeGenerator {
	private:
		unsigned int _seed;
		bool _useUserSeed = false;
		data::MazeSize _size = data::MazeSize();
		std::vector<std::vector<Cell>> _maze;
		data::Point _start = data::Point();
		data::Point _end = data::Point();

		void Initialize();
		void Resize();
		void CheckStart();
		void CheckEnd();
		size_t FindRoot(const std::vector<size_t>& parent, size_t it);
		unsigned int GenerateSeed();

	public:
		MazeGenerator();
		MazeGenerator(unsigned int seed);
		MazeGenerator(const data::MazeSize& size);
		MazeGenerator(unsigned int seed, const data::MazeSize& size);

		const unsigned int GetSeed() const;
		const data::MazeSize& GetSize() const;
		const std::vector<std::vector<Cell>>& GetMaze() const;
		void SetSeed(unsigned int seed);
		void SetSize(const data::MazeSize& size);
		void SetSize(size_t width, size_t height);
		void SetStart(const data::Point& start);
		void SetStart(int x, int y);
		void SetEnd(const data::Point& end);
		void SetEnd(int x, int y);

		void Generate();
	};
}

#endif // MAZE_GENERATOR_H