#include "maze_path_finder.h"

#pragma region MazePathFinderConstructor

mpf::MazePathFinder::MazePathFinder(mg::Maze& maze) : _maze(maze) { }

#pragma endregion

#pragma region MazePathFinderGetSet

const std::vector<mg::data::Point>& mpf::MazePathFinder::GetPath() const {
    return _path;
}

std::vector<mg::data::Point>& mpf::MazePathFinder::GetPath() {
    return _path;
}

void mpf::MazePathFinder::SetMaze(const mg::Maze& maze) {
    _maze = maze;
}

#pragma endregion