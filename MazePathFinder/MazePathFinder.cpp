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

const bool mpf::MazePathFinder::WallsIsCorrect(const int& newX, const int& newY, const std::vector<std::vector<bool>>& visited) const {
    return newX >= 0 && newX < _maze.size()
        && newY >= 0 && newY < _maze[0].size()
        && !visited[newX][newY];
}

void mpf::MazePathFinder::FindPath() {
    if (_maze.empty() || _maze[0].empty()) return;

    _path.clear();

    mg::Point start, end;
    std::vector<std::vector<mg::Point>> prev(_maze.size(), std::vector<mg::Point>(_maze[0].size()));

    for (int i = 0; i < _maze.size(); ++i) {
        for (int j = 0; j < _maze[i].size(); ++j) {
            if (_maze[i][j].GetType() == mg::CellType::Start) start = _maze[i][j].GetPosition();
            if (_maze[i][j].GetType() == mg::CellType::End) end = _maze[i][j].GetPosition();
        }
    }

    std::queue<mg::Point> queue;
    std::vector<std::vector<bool>> visited(_maze.size(), std::vector<bool>(_maze[0].size(), false));
    queue.push(start);
    visited[start.x][start.y] = true;

    while (!queue.empty()) {
        mg::Point current = queue.front();
        queue.pop();

        if (current == end) {
            std::vector<mg::Point> path;
            while (current != start) {
                path.push_back(current);
                current = prev[current.x][current.y];
            }
            path.push_back(start);
            std::reverse(path.begin(), path.end());
            _path = path;
            break;
        }

        std::vector<mg::Point> directions = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

        for (const auto& dir : directions) {
            int newX = current.x + dir.x, newY = current.y + dir.y;

            if (WallsIsCorrect(newX, newY, visited)) {
                queue.push(_maze[newX][newY].GetPosition());
                visited[newX][newY] = true;
                prev[newX][newY] = current;
                _maze[newX][newY].SetVisitedState(true);
            }
        }
    }
}

#pragma endregion