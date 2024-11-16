#pragma once

#ifndef MAZE_PATH_FINDER_H
#define MAZE_PATH_FINDER_H

#include <vector>
#include <cell.h>

namespace mpf {
	class MazePathFinder {
	private:
		std::vector<std::vector<mg::Cell>>& _maze;
	    std::vector<mg::data::Point> _path;

		const bool DepthFirstSearch(const mg::data::Point& current, const mg::data::Point& end);
		const bool CanMove(const mg::data::Point& from, const mg::data::Point& to);

	public:
		MazePathFinder(std::vector<std::vector<mg::Cell>>& maze);

		const std::vector<mg::data::Point>& GetPath() const;
		void SetMaze(const std::vector<std::vector<mg::Cell>>& maze);

		void FindPath();
	};
}

#endif // MAZE_PATH_FINDER_H