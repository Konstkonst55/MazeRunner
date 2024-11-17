#include "kruskal_generator.h"

#include <random>
#include <algorithm>
#include <numeric>

/// <summary>
/// Нахождение следующего корня при генерации лабиринта
/// </summary>
/// <param name="parent"></param>
/// <param name="it"></param>
/// <returns></returns>
size_t mg::gen::KruskalMazeGenerator::FindRoot(const std::vector<size_t>& parent, size_t it) {
    return parent[it] == it ? it : FindRoot(parent, parent[it]);
}

/// <summary>
/// Генерация лабиринта методом Краскала
/// </summary>
void mg::gen::KruskalMazeGenerator::Generate() {
    std::mt19937 rng;
    _useUserSeed ? rng.seed(_seed) : rng.seed(GenerateSeed());
    _maze.Initialize();

    std::vector<std::pair<size_t, size_t>> walls;
    data::MazeSize size = _maze.GetSize();

    for (size_t y = 0; y < size.height; y++) {
        for (size_t x = 0; x < size.width; x++) {
            if (x < size.width - 1) walls.push_back({ y, x });
            if (y < size.height - 1) walls.push_back({ y, x + size.width });
        }
    }

    std::shuffle(walls.begin(), walls.end(), rng);
    std::vector<size_t> parent(size.height * size.width);
    std::iota(parent.begin(), parent.end(), 0);

    for (const auto& wall : walls) {
        size_t y = wall.first, x = wall.second % size.width;
        size_t y2 = (wall.second < size.width) ? y : y + 1, x2 = (wall.second < size.width) ? x + 1 : x;
        size_t root1 = FindRoot(parent, y * size.width + x), root2 = FindRoot(parent, y2 * size.width + x2);

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
}

