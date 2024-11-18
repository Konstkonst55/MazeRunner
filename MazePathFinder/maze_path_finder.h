#pragma once

#ifndef MAZE_PATH_FINDER_H
#define MAZE_PATH_FINDER_H

#include <vector>
#include <maze.h>

namespace mpf {
	class MazePathFinder {
	private:
		mg::Maze& _maze;
	    std::vector<mg::data::Point> _path;

		const bool DepthFirstSearch(const mg::data::Point& current, const mg::data::Point& end);
		const bool CanMove(const mg::data::Point& from, const mg::data::Point& to);

	public:
		MazePathFinder() = default;
		MazePathFinder(mg::Maze& maze);
		~MazePathFinder() = default;

		const std::vector<mg::data::Point>& GetPath() const;
		std::vector<mg::data::Point>& GetPath();
		void SetMaze(const mg::Maze& maze);

		void FindPath();
	};
}

#endif // MAZE_PATH_FINDER_H