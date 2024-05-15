
#include "MazeGenerator.h"
#include <random>
#include <algorithm>
#include <numeric>

#pragma region MazeGeneratorConstructor

mg::MazeGenerator::MazeGenerator()
    : _seed(GenerateSeed()), _size(MazeSize()), _maze(_size.height, std::vector<Cell>(_size.width)), _useUserSeed(false) { }

mg::MazeGenerator::MazeGenerator(unsigned int seed)
    : _seed(seed), _size(MazeSize()), _maze(_size.height, std::vector<Cell>(_size.width)), _useUserSeed(true) { }

mg::MazeGenerator::MazeGenerator(MazeSize size)
    : _seed(GenerateSeed()), _size(size), _maze(size.height, std::vector<Cell>(size.width)), _useUserSeed(false) { }

mg::MazeGenerator::MazeGenerator(unsigned int seed, MazeSize size)
    : _seed(seed), _size(size), _maze(size.height, std::vector<Cell>(size.width)), _useUserSeed(true) {
    MazeInit();
    _start = mg::Point(0, 0);
    _end = mg::Point(_size.height - 1, _size.width - 1);
}

#pragma endregion

#pragma region MazeGeneratorGetSet

const unsigned int mg::MazeGenerator::GetSeed() const {
    return _seed;
}

const mg::MazeSize& mg::MazeGenerator::GetSize() const {
    return _size;
}

const std::vector<std::vector<mg::Cell>>& mg::MazeGenerator::GetMaze() const {
    return _maze;
}

void mg::MazeGenerator::SetSeed(unsigned int seed) {
    _seed = seed;
}

void mg::MazeGenerator::SetSize(const MazeSize& size) {
    _size = size;
}

void mg::MazeGenerator::SetStart(const Point& start){
    _start = start;
}

void mg::MazeGenerator::SetEnd(const Point& end) {
    _end = end;
}

#pragma endregion

#pragma region MazeGeneratorLogic

/// <summary>
/// Иннициализация лабиринта - создание всех ячеек
/// </summary>
void mg::MazeGenerator::MazeInit() {
    for (unsigned int y = 0; y < _size.height; y++) {
        for (unsigned int x = 0; x < _size.width; x++) {
            _maze[y][x] = Cell(Point(x, y), WallStates(), Default, false);
        }
    }
}

/// <summary>
/// Генерация лабиринта методом Краскала
/// </summary>
void mg::MazeGenerator::Generate() {
    std::mt19937 rng;
    _useUserSeed ? rng.seed(_seed) : rng.seed(GenerateSeed());
    MazeInit();

    std::vector<std::pair<unsigned int, unsigned int>> walls;
    for (unsigned int y = 0; y < _size.height; ++y) {
        for (unsigned int x = 0; x < _size.width; ++x) {
            if (x < _size.width - 1) walls.push_back({ y, x });
            if (y < _size.height - 1) walls.push_back({ y, x + _size.width });
        }
    }

    std::shuffle(walls.begin(), walls.end(), rng);
    std::vector<int> parent(_size.height * _size.width);
    std::iota(parent.begin(), parent.end(), 0);

    for (const auto& wall : walls) {
        int y = wall.first, x = wall.second % _size.width;
        int y2 = (wall.second < _size.width) ? y : y + 1;
        int x2 = (wall.second < _size.width) ? x + 1 : x;

        int root1 = FindRoot(parent, y * _size.width + x);
        int root2 = FindRoot(parent, y2 * _size.width + x2);

        if (root1 != root2) {
            parent[root2] = root1;
            if (y2 == y + 1) {
                _maze[y][x].SetWallState(2, Open);
                _maze[y2][x].SetWallState(0, Open);
            }
            else {
                _maze[y][x].SetWallState(1, Open);
                _maze[y][x2].SetWallState(3, Open);
            }
        }
    }

    _maze[_start.x][_start.y].SetType(Start);
    _maze[_end.x][_end.y].SetType(End);
}

/// <summary>
/// Генерация случайного сида
/// </summary>
/// <returns>Случайный сид</returns>
unsigned int mg::MazeGenerator::GenerateSeed() {
    std::random_device rd;
    return rd();
}

/// <summary>
/// Нахождение следующего корня при генерации лабиринта
/// </summary>
/// <param name="parent"></param>
/// <param name="i"></param>
/// <returns></returns>
int mg::MazeGenerator::FindRoot(std::vector<int>& parent, int i) {
    if (parent[i] == i) return i;
    return parent[i] = FindRoot(parent, parent[i]);
}

#pragma endregion