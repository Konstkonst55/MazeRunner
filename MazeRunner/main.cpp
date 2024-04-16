#include <SFML/Graphics.hpp>
#include <Cell.h>
#include "MazeView.h"
#include <random>

bool GetRandomBool() {
    static std::default_random_engine generator(std::random_device{}());
    std::uniform_int_distribution<int> distribution(0, 1);
    return distribution(generator);
}

WallState SafeCastToWallState(bool value) {
    return value ? WallState::Open : WallState::Close;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "MazeRunner");
    std::vector<std::vector<Cell>> maze(5, std::vector<Cell>(5));

    for (int y = 0; y < maze.size(); y++) {
        for (int x = 0; x < maze[y].size(); x++) {
            Point position(x, y);
            WallStates walls(SafeCastToWallState(GetRandomBool()), SafeCastToWallState(GetRandomBool()), SafeCastToWallState(GetRandomBool()), SafeCastToWallState(GetRandomBool()));
            maze[y][x] = Cell(position, walls);
        }
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)window.close();
        }

        view::Render(maze, window, 100);
    }

    system("PAUSE");
    return 0;
}