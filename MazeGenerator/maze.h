#pragma once

#ifndef MAZE_H
#define MAZE_H

#include "cell.h"
#include "maze_size.h"

#include <vector>

namespace mg {
	namespace us {
		using iterator = std::vector<std::vector<mg::Cell>>::iterator;
		using constIterator = std::vector<std::vector<mg::Cell>>::const_iterator;
	};

	/// <summary>
	/// Класс для работы с лабиринтом
	/// </summary>
	class Maze {
	private:
		std::vector<std::vector<Cell>> _maze;
		data::MazeSize _size;
		data::Point _start;
		data::Point _end;

		void Resize();
		void CheckStart();
		void CheckEnd();

	public:
		Maze(const data::MazeSize& size = data::MazeSize());
		~Maze() = default;
		
		const data::MazeSize& GetSize() const;
		const std::vector<std::vector<Cell>>& GetMaze() const;
		const data::Point& GetStart() const;
		const data::Point& GetEnd() const;
		void SetSize(const data::MazeSize& size);
		void SetSize(size_t width, size_t height);
		void SetStart(const data::Point& start);
		void SetStart(int x, int y);
		void SetEnd(const data::Point& end);
		void SetEnd(int x, int y);

		Cell& operator()(size_t x, size_t y);
		const Cell& operator()(size_t x, size_t y) const;
		std::vector<Cell>& operator[](size_t y);
		const std::vector<Cell>& operator[](size_t y) const;

		std::vector<mg::Cell>& at(size_t y);
		const std::vector<mg::Cell>& at(size_t y) const;
		us::iterator begin(), end();
		us::constIterator begin() const, end() const, cbegin() const, cend() const;

		void Initialize();
	};
}

#endif // MAZE_H