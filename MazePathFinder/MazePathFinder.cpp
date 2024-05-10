#include "MazePathFinder.h"
#include <queue>

#pragma region MazePathFinderConstructor

mpf::MazePathFinder::MazePathFinder(std::vector<std::vector<mg::Cell>> maze)
    : _maze(maze) { }

#pragma endregion

#pragma region MazePathFinderGetSet

const std::vector<mg::Point> mpf::MazePathFinder::GetPath() const {
    return _path;
}

void mpf::MazePathFinder::SetMaze(std::vector<std::vector<mg::Cell>> maze) {
    _maze = maze;
}

#pragma endregion

#pragma region MazePathFinderLogic

const bool mpf::MazePathFinder::DepthFirstSearch(const mg::Point& current, const mg::Point& end) {
    if (current == end) {
        _path.push_back(current);
        return true;
    }

    if (_maze[current.x][current.y].IsVisited()) {
        return false;
    }

    _maze[current.x][current.y].SetVisitedState(true);

    std::vector<mg::Point> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    for (const auto& dir : directions) {
        mg::Point next = { current.x + dir.x, current.y + dir.y };
        if (next.x >= 0 && next.x < _maze.size() && next.y >= 0 && next.y < _maze[0].size() && !_maze[next.x][next.y].IsVisited()) {
            bool canMove = false;

            canMove = (dir.x == -1 && _maze[current.x][current.y].GetWalls().top == mg::Open) ||
                (dir.x == 1 && _maze[current.x][current.y].GetWalls().bottom == mg::Open) ||
                (dir.y == -1 && _maze[current.x][current.y].GetWalls().left == mg::Open) ||
                (dir.y == 1 && _maze[current.x][current.y].GetWalls().right == mg::Open);

            if (canMove) {
                if (DepthFirstSearch(next, end)) {
                    _path.push_back(current);
                    return true;
                }
            }
        }
    }

    return false;
}

void mpf::MazePathFinder::FindPath() {
    if (_maze.empty() || _maze[0].empty()) {
        return;
    }

    _path.clear();

    mg::Point start, end;

    for (int i = 0; i < _maze.size(); ++i) {
        for (int j = 0; j < _maze[i].size(); ++j) {
            if (_maze[i][j].GetType() == mg::Start) {
                start = _maze[i][j].GetPosition();
            }
            else if (_maze[i][j].GetType() == mg::End) {
                end = _maze[i][j].GetPosition();
            }
        }
    }

    if (start == mg::Point(-1, -1) || end == mg::Point(-1, -1)) {
        return;
    }

    if (!DepthFirstSearch(start, end)) {
        return;
    }
}

#pragma endregion