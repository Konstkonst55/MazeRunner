
#include "MazeGenerator.h"
#include <random>
#include <algorithm>
#include <numeric>

mg::MazeGenerator::MazeGenerator()
    : MazeGenerator(GenerateSeed()) { }

mg::MazeGenerator::MazeGenerator(unsigned int seed)
    : MazeGenerator(seed, MazeSize()) { }

mg::MazeGenerator::MazeGenerator(MazeSize size)
    : MazeGenerator(GenerateSeed(), size) { }

mg::MazeGenerator::MazeGenerator(unsigned int seed, MazeSize size)
    : _seed(seed), _size(size), _maze(size.height, std::vector<Cell>(size.width)) {
    for (unsigned int y = 0; y < _size.height; y++) {
        for (unsigned int x = 0; x < _size.width; x++) {
            _maze[y][x] = Cell(Point(x, y), WallStates(), Default, false);
        }
    }
}

unsigned int mg::MazeGenerator::GetSeed() {
    return _seed;
}

void mg::MazeGenerator::SetSeed(unsigned int seed) {
    _seed = seed;
}

mg::MazeSize mg::MazeGenerator::GetSize() {
    return _size;
}

void mg::MazeGenerator::SetSize(MazeSize size) {
    _size = size;
}

std::vector<std::vector<mg::Cell>>& mg::MazeGenerator::GetMaze() {
    return _maze;
}

unsigned int mg::MazeGenerator::GenerateSeed() {
    std::random_device rd;
    return rd();
}

void mg::MazeGenerator::Generate() {
    std::mt19937 rng(_seed);

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
                _maze[y][x].GetWalls().bottom = Open;
                _maze[y2][x].GetWalls().top = Open;
            }
            else {
                _maze[y][x].GetWalls().right = Open;
                _maze[y][x2].GetWalls().left = Open;
            }
        }
    }

    _maze[0][0].SetType(Start);
    _maze[_size.height -1][_size.width - 1].SetType(End);
}

int mg::MazeGenerator::FindRoot(std::vector<int>&parent, int i) {
    if (parent[i] == i) return i;
    return parent[i] = FindRoot(parent, parent[i]);
}