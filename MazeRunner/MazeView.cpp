
#include "MazeView.h"

void view::Render(std::vector<std::vector<Cell>> maze, sf::RenderWindow& window, const int cellSize) {
    const int thickness = 2, border = 10;
    sf::RectangleShape wallShape(sf::Vector2f(cellSize, thickness));
    wallShape.setFillColor(sf::Color::White);

    for (auto& row : maze) {
        for (auto& cell : row) {
            Point position = cell.GetPosition();

            if (cell.GetWalls().top == WallState::Close) {
                wallShape.setPosition(position.x * cellSize + border, position.y * cellSize + border);
                window.draw(wallShape);
            }

            if (cell.GetWalls().right == WallState::Close) {
                wallShape.setPosition((position.x + 1) * cellSize + border, position.y * cellSize + border);
                wallShape.rotate(90);
                window.draw(wallShape);
                wallShape.rotate(-90);
            }

            if (cell.GetWalls().bottom == WallState::Close) {
                wallShape.setPosition(position.x * cellSize + border, (position.y + 1) * cellSize + border);
                window.draw(wallShape);
            }

            if (cell.GetWalls().left == WallState::Close) {
                wallShape.setPosition(position.x * cellSize + border, position.y * cellSize + border);
                wallShape.rotate(90);
                window.draw(wallShape);
                wallShape.rotate(-90);
            }
        }
    }

    window.display();
}
