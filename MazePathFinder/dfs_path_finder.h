#pragma once

#ifndef DFS_PATH_FINDER_H
#define DFS_PATH_FINDER_H

#include "maze_path_finder.h"

#include <vector>
#include <maze.h>

namespace mpf {
	class DFSPathFinder : public MazePathFinder {
	private:
		bool DepthFirstSearch(const mg::data::Point& current, const mg::data::Point& end);
		bool CanMove(const mg::data::Point& from, const mg::data::Point& to);

	public:
		using MazePathFinder::MazePathFinder;

		void FindPath() override;
	};
}

#endif // DFS_PATH_FINDER_H