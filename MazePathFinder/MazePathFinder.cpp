#include "MazePathFinder.h"

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

/// <summary>
/// Проверка на проходимость между ячейками
/// </summary>
/// <param name="from">Начальная ячейка</param>
/// <param name="to">Конечная ячейка</param>
/// <returns>true, если можно пройти</returns>
const bool mpf::MazePathFinder::CanMove(const mg::Point& from, const mg::Point& to) {
    return from.x == to.x ?
        from.y < to.y ? _maze[from.x][from.y].GetWalls().right == mg::Open : _maze[from.x][from.y].GetWalls().left == mg::Open :
        from.x < to.x ? _maze[from.x][from.y].GetWalls().bottom == mg::Open : _maze[from.x][from.y].GetWalls().top == mg::Open;
}

/// <summary>
/// Поиск пути в глубину
/// </summary>
/// <param name="current">Текущая ячейка</param>
/// <param name="end">Конечная ячейка</param>
/// <returns>true, если найден</returns>
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
            if (CanMove(current, next)) {
                if (DepthFirstSearch(next, end)) {
                    _path.push_back(current);
                    return true;
                }
            }
        }
    }

    return false;
}

/// <summary>
/// Поиск пути в лабиринте
/// </summary>
void mpf::MazePathFinder::FindPath() {
    if (_maze.empty() || _maze[0].empty()) {
        return;
    }

    _path.clear();

    mg::Point start, end;

    for (const auto& row : _maze) {
        for (const auto& cell : row) {
            if (cell.GetType() == mg::Start) {
                start = cell.GetPosition();
            }
            else if (cell.GetType() == mg::End) {
                end = cell.GetPosition();
            }
        }
    }

    DepthFirstSearch(start, end);
}

#pragma endregion