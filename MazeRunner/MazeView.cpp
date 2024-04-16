
#include "MazeView.h"

void view::Render(std::vector<std::vector<Cell>> maze, sf::RenderWindow& window, const int cellSize) {
    const int windowWidth = maze[0].size() * cellSize;
    const int windowHeight = maze.size() * cellSize;
    const int lineThickness = 2;

    sf::RectangleShape line(sf::Vector2f(cellSize, lineThickness));

    window.clear();

    for (size_t y = 0; y < maze.size(); y++) {
        for (size_t x = 0; x < maze[y].size(); x++) {
            Cell& cell = maze[y][x];
            const WallStates walls = cell.GetWalls();

            if (walls.top) {
                line.setPosition(x * cellSize, y * cellSize);
                window.draw(line);
            }

            if (walls.right) {
                line.setPosition(x * cellSize, y * cellSize);
                line.rotate(90);
                window.draw(line);
                line.rotate(-90);
            }

            if (walls.bottom) {
                line.setPosition(x * cellSize, y * cellSize);
                line.rotate(180);
                window.draw(line);
                line.rotate(-180);
            }

            if (walls.left) {
                line.setPosition(x * cellSize, y * cellSize);
                line.rotate(-90);
                window.draw(line);
                line.rotate(90);
            }
        }
    }

    window.display();
}
