
#include "MazeView.h"

void view::Render(std::vector<std::vector<mg::Cell>> maze, sf::RenderWindow& window, const int cellSize) {
    const int thickness = 2, border = 10;
    sf::RectangleShape wallShape(sf::Vector2f(cellSize, thickness));
    wallShape.setFillColor(sf::Color::White);

    for (auto& row : maze) {
        for (auto& cell : row) {
            mg::Point position = cell.GetPosition();

            if (cell.GetWalls().top == mg::WallState::Close) {
                wallShape.setPosition(position.x * cellSize + border, position.y * cellSize + border);
                window.draw(wallShape);
            }

            if (cell.GetWalls().right == mg::WallState::Close) {
                wallShape.setPosition((position.x + 1) * cellSize + border, position.y * cellSize + border);
                wallShape.rotate(90);
                window.draw(wallShape);
                wallShape.rotate(-90);
            }

            if (cell.GetWalls().bottom == mg::WallState::Close) {
                wallShape.setPosition(position.x * cellSize + border, (position.y + 1) * cellSize + border);
                window.draw(wallShape);
            }

            if (cell.GetWalls().left == mg::WallState::Close) {
                wallShape.setPosition(position.x * cellSize + border, position.y * cellSize + border);
                wallShape.rotate(90);
                window.draw(wallShape);
                wallShape.rotate(-90);
            }
        }
    }

    window.display();
}
