#pragma once

#ifndef MAZE_PATH_FINDER_H
#define MAZE_PATH_FINDER_H

#include <vector>
#include <maze.h>

namespace mpf {
	/// <summary>
	/// Класс для поиска пути в лабиринте
	/// </summary>
	class MazePathFinder {
	protected:
		mg::Maze& _maze;
		std::vector<mg::data::Point> _path;

	public:
		MazePathFinder() = default;
		MazePathFinder(mg::Maze& maze);
		~MazePathFinder() = default;

		const std::vector<mg::data::Point>& GetPath() const;
		std::vector<mg::data::Point>& GetPath();
		void SetMaze(const mg::Maze& maze);

		virtual void FindPath() = 0;
	};
}

#endif // MAZE_PATH_FINDER_H