#include <SFML/Graphics.hpp>
#include <MazeGenerator.h>
#include "MazeView.h"
#include <random>
#include <chrono>
#include <thread>

bool GetRandomBool() {
    static std::default_random_engine generator(std::random_device{}());
    std::uniform_int_distribution<int> distribution(0, 1);
    return distribution(generator);
}

WallState SafeCastToWallState(bool value) {
    return value ? WallState::Open : WallState::Close;
}

int main() {
    const int msize = 25;
    sf::RenderWindow window(sf::VideoMode(1200, 900), "MazeRunner");
    std::vector<std::vector<Cell>> maze;
    mg::MazeGenerator mazeGen(MazeSize(msize, msize));

    maze = mazeGen.Generate();

    for (auto cellx : maze) {
        for (auto cell : cellx) {
            cell.Print();
        }
    }

    view::Render(maze, window, 25);
    maze.clear();

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
        }
    }

    system("PAUSE");
    return 0;
}