﻿#include "maze_generator.h"
#include <random>
#include <algorithm>
#include <numeric>

#pragma region MazeGeneratorConstructor

mg::MazeGenerator::MazeGenerator() : MazeGenerator(GenerateSeed(), data::MazeSize()) {
    _useUserSeed = false;
}

mg::MazeGenerator::MazeGenerator(unsigned int seed) : MazeGenerator(seed, data::MazeSize()) {
    _useUserSeed = true;
}

mg::MazeGenerator::MazeGenerator(const data::MazeSize& size) : MazeGenerator(GenerateSeed(), size) { 
    _useUserSeed = false;
}

mg::MazeGenerator::MazeGenerator(unsigned int seed, const data::MazeSize& size) : _seed(seed), _size(size), _maze(size.height, std::vector<Cell>(size.width)) {
    Initialize();
    _useUserSeed = true;
}

#pragma endregion

#pragma region MazeGeneratorGetSet

const unsigned int mg::MazeGenerator::GetSeed() const {
    return _seed;
}

const mg::data::MazeSize& mg::MazeGenerator::GetSize() const {
    return _size;
}

const std::vector<std::vector<mg::Cell>>& mg::MazeGenerator::GetMaze() const {
    return _maze;
}

void mg::MazeGenerator::SetSeed(unsigned int seed) {
    _seed = seed;
    _useUserSeed = true;
}

void mg::MazeGenerator::SetSize(const data::MazeSize& size) {
    _size = size;
    Resize();
    Initialize();
}

void mg::MazeGenerator::SetSize(size_t width, size_t height) {
    _size = data::MazeSize(width, height);
    Resize();
    Initialize();
}

void mg::MazeGenerator::SetStart(const data::Point& start){
    _start = start;
    CheckStart();
    Initialize();
}

void mg::MazeGenerator::SetStart(int x, int y) {
    _start = data::Point(x, y);
    CheckStart();
    Initialize();
}

void mg::MazeGenerator::SetEnd(const data::Point& end) {
    _end = end;
    CheckEnd();
    Initialize();
}

void mg::MazeGenerator::SetEnd(int x, int y) {
    _end = data::Point(x, y);
    CheckEnd();
    Initialize();
}

#pragma endregion

#pragma region MazeGeneratorLogic

/// <summary>
/// Иннициализация лабиринта - создание всех ячеек
/// </summary>
void mg::MazeGenerator::Initialize() {
    for (size_t y = 0; y < _size.height; y++) {
        for (size_t x = 0; x < _size.width; x++) {
            _maze[y][x] = Cell(data::Point(static_cast<int>(x), static_cast<int>(y)), data::WallStates(), data::CellType::Default, false);
        }
    }
}

/// <summary>
/// Изменение размера лабиринта
/// </summary>
void mg::MazeGenerator::Resize() {
    _maze.resize(_size.height, std::vector<Cell>(_size.width));

    for (auto& row : _maze) {
        row.resize(_size.width);
    }

    CheckStart();
    CheckEnd();
}

/// <summary>
/// Проверка выхода начальной точки за границы лабиринта
/// </summary>
void mg::MazeGenerator::CheckStart() {
    if (_start.x < 0) {
        _start.x = 0;
    }
    else if (_start.x >= _size.width) {
        _start.x = _size.width - 1;
    }

    if (_start.y < 0) {
        _start.y = 0;
    }
    else if (_start.y >= _size.height) {
        _start.y = _size.height - 1;
    }
}

/// <summary>
/// Проверка выхода конечной точки за границы лабиринта
/// </summary>
void mg::MazeGenerator::CheckEnd() {
    if (_end.x < 0) {
        _end.x = 0;
    }
    else if (_end.x >= _size.width) {
        _end.x = _size.width - 1;
    }

    if (_end.y < 0) {
        _end.y = 0;
    }
    else if (_end.y >= _size.height) {
        _end.y = _size.height - 1;
    }
}

/// <summary>
/// Генерация лабиринта методом Краскала
/// </summary>
void mg::MazeGenerator::Generate() {
    std::mt19937 rng;
    _useUserSeed ? rng.seed(_seed) : rng.seed(GenerateSeed());
    Initialize();

    std::vector<std::pair<size_t, size_t>> walls;

    for (size_t y = 0; y < _size.height; y++) {
        for (size_t x = 0; x < _size.width; x++) {
            if (x < _size.width - 1) walls.push_back({ y, x });
            if (y < _size.height - 1) walls.push_back({ y, x + _size.width });
        }
    }

    std::shuffle(walls.begin(), walls.end(), rng);
    std::vector<size_t> parent(_size.height * _size.width);
    std::iota(parent.begin(), parent.end(), 0);

    for (const auto& wall : walls) {
        size_t y = wall.first, x = wall.second % _size.width;
        size_t y2 = (wall.second < _size.width) ? y : y + 1, x2 = (wall.second < _size.width) ? x + 1 : x;
        size_t root1 = FindRoot(parent, y * _size.width + x), root2 = FindRoot(parent, y2 * _size.width + x2);

        if (root1 != root2) {
            parent[root2] = root1;

            if (y2 == y + 1) {
                _maze[y][x].SetWallState(2, data::WallState::Open);
                _maze[y2][x].SetWallState(0, data::WallState::Open);
            }
            else {
                _maze[y][x].SetWallState(1, data::WallState::Open);
                _maze[y][x2].SetWallState(3, data::WallState::Open);
            }
        }
    }

    _maze[_start.x][_start.y].SetType(data::CellType::Start);
    _maze[_end.x][_end.y].SetType(data::CellType::End);
}

/// <summary>
/// Генерация случайного сида
/// </summary>
/// <returns>Случайный сид</returns>
unsigned int mg::MazeGenerator::GenerateSeed() {
    _useUserSeed = false;
    std::random_device rd;
    return rd();
}

/// <summary>
/// Нахождение следующего корня при генерации лабиринта
/// </summary>
/// <param name="parent"></param>
/// <param name="it"></param>
/// <returns></returns>
size_t mg::MazeGenerator::FindRoot(const std::vector<size_t>& parent, size_t it) {
    return parent[it] == it ? it : FindRoot(parent, parent[it]);
}

#pragma endregion