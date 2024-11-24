#pragma once

#ifndef KRUSKAL_MAZE_GENERATOR_H
#define KRUSKAL_MAZE_GENERATOR_H

#include "maze_generator.h"

#include <vector>

namespace mg::gen {
    /// <summary>
    /// Класс генерации лабиринта методом Краскала
    /// </summary>
    class KruskalMazeGenerator : public MazeGenerator {
    private:
        size_t FindRoot(const std::vector<size_t>& parent, size_t it);

    public: 
        using MazeGenerator::MazeGenerator;

        void Generate() override;
    };
}

#endif // KRUSKAL_MAZE_GENERATOR_H
