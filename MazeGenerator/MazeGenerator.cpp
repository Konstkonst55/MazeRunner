
#include "MazeGenerator.h"
#include <random>
#include <chrono>
#include <algorithm>
#include <stack>
#include <functional>
#include <stdlib.h>

mg::MazeGenerator::MazeGenerator()
    : MazeGenerator(GenerateSeed()) { }

mg::MazeGenerator::MazeGenerator(unsigned int seed)
    : MazeGenerator(seed, MazeSize()) { }

mg::MazeGenerator::MazeGenerator(MazeSize size)
    : MazeGenerator(GenerateSeed(), size) { }

mg::MazeGenerator::MazeGenerator(unsigned int seed, MazeSize size)
    : _seed(seed), _size(size) { }

unsigned int mg::MazeGenerator::GetSeed() {
    return _seed;
}

void mg::MazeGenerator::SetSeed(unsigned int seed) {
    _seed = seed;
}

MazeSize mg::MazeGenerator::GetSize() {
    return _size;
}

void mg::MazeGenerator::SetSize(MazeSize size) {
    _size = size;
}

unsigned int mg::MazeGenerator::GenerateSeed() {
    std::random_device rd;
    return rd();
}

std::vector<std::vector<Cell>> mg::MazeGenerator::Generate() {
    std::vector<std::vector<Cell>> maze(_size.height, std::vector<Cell>(_size.width));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);

    for (int y = 0; y < _size.height; ++y) {
        for (int x = 0; x < _size.width; ++x) {
            maze[y][x] = Cell(Point(x, y), WallStates(), false);
        }
    }

    std::function<void(int, int)> generateMaze = [&](int x, int y) {
        maze[y][x].SetVisitedState(true);

        std::vector<std::pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
        std::shuffle(directions.begin(), directions.end(), gen);

        for (auto& dir : directions) {
            int newX = x + dir.first;
            int newY = y + dir.second;

            if (newX >= 0 && newX < _size.width && newY >= 0 && newY < _size.height && !maze[newY][newX].IsVisited()) {
                if (dir.first == -1) maze[y][x].SetWallState(3, Close);
                if (dir.first == 1) maze[y][x].SetWallState(1, Close);
                if (dir.second == -1) maze[y][x].SetWallState(0, Close);
                if (dir.second == 1) maze[y][x].SetWallState(2, Close);

                generateMaze(newX, newY);
            }
        }
    };

    generateMaze(0, 0);

    maze[_size.height - 1][_size.width - 1].SetWallState(0, Open);
    maze[_size.height - 1][_size.width - 1].SetWallState(3, Open);

    return maze;
}