#pragma once

#ifndef MAZE_PATH_FINDER_H
#define MAZE_PATH_FINDER_H

#include <vector>
#include <Cell.h>

namespace mpf {
	class MazePathFinder {
	private:
		std::vector<std::vector<mg::Cell>> _maze;
	    std::vector<mg::Point> _path;

		const bool DepthFirstSearch(const mg::Point&, const mg::Point&);
		const bool CanMove(const mg::Point&, const mg::Point&);

	public:
		MazePathFinder(std::vector<std::vector<mg::Cell>>);

		const std::vector<mg::Point> GetPath() const;
		void SetMaze(std::vector<std::vector<mg::Cell>>);

		void FindPath();
	};
}

#endif // MAZE_PATH_FINDER_H