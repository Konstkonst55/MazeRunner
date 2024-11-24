#include "dfs_path_finder.h"

#include <stdexcept>

/// <summary>
/// �������� �� ������������ ����� ��������
/// </summary>
/// <param name="from">��������� ������</param>
/// <param name="to">�������� ������</param>
/// <returns>true, ���� ����� ������</returns>
bool mpf::DFSPathFinder::CanMove(const mg::data::Point& from, const mg::data::Point& to) {
    return from.x == to.x ?
        from.y < to.y ? _maze[from.x][from.y].GetWalls().right == mg::data::Open : _maze[from.x][from.y].GetWalls().left == mg::data::Open :
        from.x < to.x ? _maze[from.x][from.y].GetWalls().bottom == mg::data::Open : _maze[from.x][from.y].GetWalls().top == mg::data::Open;
}

/// <summary>
/// ����� ���� � �������
/// </summary>
/// <param name="current">������� ������</param>
/// <param name="end">�������� ������</param>
/// <returns>true, ���� ������</returns>
bool mpf::DFSPathFinder::DepthFirstSearch(const mg::data::Point& current, const mg::data::Point& end) {
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
/// ����� ���� � ���������
/// </summary>
void mpf::DFSPathFinder::FindPath() {
    if (_maze.GetMaze().empty() || _maze[0].empty()) {
        throw std::runtime_error("Maze does not contain cells!");
    }

    _path.clear();

    DepthFirstSearch(_maze.GetStart(), _maze.GetEnd());
}