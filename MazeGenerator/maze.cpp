#include "maze.h"

#pragma region MazeConstructor

mg::Maze::Maze(const data::MazeSize& size) : _size(size), _maze(size.height, std::vector<Cell>(size.width)) {
    Initialize();
    _start = data::Point(0, 0);
    _end = data::Point(static_cast<int>(_size.height - 1), static_cast<int>(_size.width - 1));
}

#pragma endregion

#pragma region MazeGetSet

const mg::data::MazeSize& mg::Maze::GetSize() const {
    return _size;
}

const std::vector<std::vector<mg::Cell>>& mg::Maze::GetMaze() const {
    return _maze;
}

const mg::data::Point& mg::Maze::GetStart() const { 
    return _start;
}

const mg::data::Point& mg::Maze::GetEnd() const {
    return _end;
}

void mg::Maze::SetSize(const data::MazeSize& size) {
    _size = size;
    Resize();
    Initialize();
}

void mg::Maze::SetSize(size_t width, size_t height) {
    _size = data::MazeSize(width, height);
    Resize();
    Initialize();
}

void mg::Maze::SetStart(const data::Point& start) {
    _start = start;
    CheckStart();
    Initialize();
}

void mg::Maze::SetStart(int x, int y) {
    _start = data::Point(x, y);
    CheckStart();
    Initialize();
}

void mg::Maze::SetEnd(const data::Point& end) {
    _end = end;
    CheckEnd();
    Initialize();
}

void mg::Maze::SetEnd(int x, int y) {
    _end = data::Point(x, y);
    CheckEnd();
    Initialize();
}

#pragma endregion

#pragma region MazeOperators

mg::Cell& mg::Maze::operator()(size_t x, size_t y) {
    return at(y).at(x);
}

const mg::Cell& mg::Maze::operator()(size_t x, size_t y) const {
    return at(y).at(x);
}

std::vector<mg::Cell>& mg::Maze::operator[](size_t y) {
    return _maze[y];
}

const std::vector<mg::Cell>& mg::Maze::operator[](size_t y) const {
    return _maze[y];
}

std::vector<mg::Cell>& mg::Maze::at(size_t y) {
    return _maze.at(y);
}

const std::vector<mg::Cell>& mg::Maze::at(size_t y) const {
    return _maze.at(y);
}

mg::us::iterator mg::Maze::begin() {
    return _maze.begin();
}

mg::us::iterator mg::Maze::end() {
    return _maze.end();
}

mg::us::constIterator mg::Maze::begin() const {
    return _maze.begin();
}

mg::us::constIterator mg::Maze::end() const {
    return _maze.end();
}

mg::us::constIterator mg::Maze::cbegin() const {
    return _maze.cbegin();
}

mg::us::constIterator mg::Maze::cend() const {
    return _maze.cend();
}

#pragma endregion

#pragma region MazeLogic

/// <summary>
/// »ннициализаци€ лабиринта - создание всех €чеек
/// </summary>
void mg::Maze::Initialize() {
    for (size_t y = 0; y < _size.height; y++) {
        for (size_t x = 0; x < _size.width; x++) {
            _maze[y][x] = Cell(data::WallStates(), false);
        }
    }
}

/// <summary>
/// »зменение размера лабиринта
/// </summary>
void mg::Maze::Resize() {
    _maze.resize(_size.height, std::vector<Cell>(_size.width));

    for (auto& row : _maze) {
        row.resize(_size.width);
    }

    CheckStart();
    CheckEnd();
}

/// <summary>
/// ѕроверка выхода начальной точки за границы лабиринта
/// </summary>
void mg::Maze::CheckStart() {
    if (_start.x < 0) {
        _start.x = 0;
    }
    else if (_start.x >= _size.width) {
        _start.x = static_cast<int>(_size.width - 1);
    }

    if (_start.y < 0) {
        _start.y = 0;
    }
    else if (_start.y >= _size.height) {
        _start.y = static_cast<int>(_size.height - 1);
    }
}

/// <summary>
/// ѕроверка выхода конечной точки за границы лабиринта
/// </summary>
void mg::Maze::CheckEnd() {
    if (_end.x < 0) {
        _end.x = 0;
    }
    else if (_end.x >= _size.width) {
        _end.x = static_cast<int>(_size.width - 1);
    }

    if (_end.y < 0) {
        _end.y = 0;
    }
    else if (_end.y >= _size.height) {
        _end.y = static_cast<int>(_size.height - 1);
    }
}

#pragma endregion