#include "maze_generator.h"

#include <random>

#pragma region MazeGeneratorConstructor

mg::gen::MazeGenerator::MazeGenerator() : MazeGenerator(GenerateSeed(), data::MazeSize()) {
    _useUserSeed = false;
}

mg::gen::MazeGenerator::MazeGenerator(unsigned int seed) : MazeGenerator(seed, data::MazeSize()) {
    _useUserSeed = true;
}

mg::gen::MazeGenerator::MazeGenerator(const data::MazeSize& size) : MazeGenerator(GenerateSeed(), size) { 
    _useUserSeed = false;
}

mg::gen::MazeGenerator::MazeGenerator(unsigned int seed, const data::MazeSize& size) : _seed(seed), _maze(Maze(size)) {
    _useUserSeed = true;
}

#pragma endregion

#pragma region MazeGeneratorGetSet

const unsigned int mg::gen::MazeGenerator::GetSeed() const {
    return _seed;
}

const mg::Maze& mg::gen::MazeGenerator::GetMaze() const {
    return _maze;
}

mg::Maze& mg::gen::MazeGenerator::GetMaze() {
    return _maze;
}

void mg::gen::MazeGenerator::SetSeed(unsigned int seed) {
    _seed = seed;
    _useUserSeed = true;
}

#pragma endregion

#pragma region MazeGeneratorLogic

/// <summary>
/// Генерация случайного сида
/// </summary>
/// <returns>Случайный сид</returns>
unsigned int mg::gen::MazeGenerator::GenerateSeed() {
    _useUserSeed = false;
    std::random_device rd;
    return rd();
}

#pragma endregion