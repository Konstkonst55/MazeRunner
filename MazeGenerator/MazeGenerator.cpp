
#include "MazeGenerator.h"
#include <random>
#include <algorithm>

namespace mg {
    MazeGenerator::MazeGenerator()
        : MazeGenerator(GenerateSeed()) { }

    MazeGenerator::MazeGenerator(unsigned int seed) 
        : MazeGenerator(seed, MazeSize()) { }

    MazeGenerator::MazeGenerator(unsigned int seed, MazeSize size)
        : _seed(seed), _size(size) { }

    unsigned int MazeGenerator::GetSeed() {
        return _seed;
    }

    void MazeGenerator::SetSeed(unsigned int seed) {
        _seed = seed;
    }

    MazeSize MazeGenerator::GetSize() {
        return _size;
    }

    void MazeGenerator::SetSize(MazeSize size) {
        _size = size;
    }

    std::vector<std::vector<Cell>> MazeGenerator::Generate() {
        return std::vector<std::vector<Cell>>(); // todo
    }

    unsigned int MazeGenerator::GenerateSeed() {
        std::random_device rd;
        return rd();
    }
}