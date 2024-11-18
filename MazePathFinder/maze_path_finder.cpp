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

#pragma region MazePathFinderLogic

/// <summary>
/// Проверка на проходимость между ячейками
/// </summary>
/// <param name="from">Начальная ячейка</param>
/// <param name="to">Конечная ячейка</param>
/// <returns>true, если можно пройти</returns>
const bool mpf::MazePathFinder::CanMove(const mg::data::Point& from, const mg::data::Point& to) {
    return from.x == to.x ?
        from.y < to.y ? _maze[from.x][from.y].GetWalls().right == mg::data::Open : _maze[from.x][from.y].GetWalls().left == mg::data::Open :
        from.x < to.x ? _maze[from.x][from.y].GetWalls().bottom == mg::data::Open : _maze[from.x][from.y].GetWalls().top == mg::data::Open;
}

/// <summary>
/// Поиск пути в глубину
/// </summary>
/// <param name="current">Текущая ячейка</param>
/// <param name="end">Конечная ячейка</param>
/// <returns>true, если найден</returns>
const bool mpf::MazePathFinder::DepthFirstSearch(const mg::data::Point& current, const mg::data::Point& end) {
    if (current == end) {
        _path.push_back(current);
        return true;
    }

    if (_maze[current.x][current.y].IsVisited()) {
        return false;
    }

    _maze[current.x][current.y].SetVisitedState(true);

    std::vector<mg::data::Point> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    for (const auto& dir : directions) {
        mg::data::Point next = { current.x + dir.x, current.y + dir.y };

        if (next.x < 0 || next.x >= _maze.GetMaze().size() || next.y < 0 || next.y >= _maze[0].size()) {
            continue;
        }

        if (_maze[next.x][next.y].IsVisited()) {
            continue;
        }

        if (!CanMove(current, next)) {
            continue;
        }

        if (DepthFirstSearch(next, end)) {
            _path.push_back(current);
            return true;
        }
    }

    return false;
}

/// <summary>
/// Поиск пути в лабиринте
/// </summary>
void mpf::MazePathFinder::FindPath() {
    if (_maze.GetMaze().empty() || _maze[0].empty()) {
        return;
    }

    _path.clear();

    DepthFirstSearch(_maze.GetStart(), _maze.GetEnd());
}

#pragma endregion