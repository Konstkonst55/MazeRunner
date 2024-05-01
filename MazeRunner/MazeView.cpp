
#include "MazeView.h"
#include <iostream>

view::MazeView::MazeView(std::vector<std::vector<mg::Cell>> maze, sf::RenderWindow& window) 
    : MazeView(maze, window, sf::Color::White) { }

view::MazeView::MazeView(std::vector<std::vector<mg::Cell>> maze, sf::RenderWindow& window, sf::Color color) 
    : MazeView(maze, window, color, 2) { }

view::MazeView::MazeView(std::vector<std::vector<mg::Cell>> maze, sf::RenderWindow& window, sf::Color color, size_t thickness) 
    : MazeView(maze, window, color, thickness, 10) { }

view::MazeView::MazeView(std::vector<std::vector<mg::Cell>> maze, sf::RenderWindow& window, sf::Color color, size_t thickness, size_t border) 
    : _maze(maze), _window(window), _color(color), _thickness(thickness), _border(border) { 
    UpdateCellSize();
}

void view::MazeView::UpdateCellSize() {
    _cellSize = {
        ((float)_window.getSize().x - _border * 2) / (float)_maze[0].size(),
        ((float)_window.getSize().y - _border * 2) / (float)_maze.size()
    };
}

void view::MazeView::DrawRectangleCenteredAt(sf::Vector2f position, sf::Color color) {
    sf::RectangleShape rectangle(sf::Vector2f(_cellSize.x, _cellSize.y));

    rectangle.setPosition(position.x, position.y);
    rectangle.setFillColor(color);

    _window.draw(rectangle);
}

void view::MazeView::SetMaze(std::vector<std::vector<mg::Cell>> maze) {
    _maze = maze;
}

void view::MazeView::SetColor(sf::Color color) {
    _color = color;
}

void view::MazeView::SetBorder(size_t border) {
    _border = border;
}

size_t view::MazeView::GetBorder() {
    return _border;
}

void view::MazeView::SetThickness(size_t thickness) {
    _thickness = thickness;
}

size_t view::MazeView::GetThickness() {
    return _thickness;
}

void view::MazeView::Render() {
    sf::RectangleShape wallShape(sf::Vector2f(_cellSize.x, _thickness));
    wallShape.setFillColor(_color);

    for (auto& row : _maze) {
        for (auto& cell : row) {
            mg::Point position = cell.GetPosition();

            if (cell.GetType() == mg::Start) {
                DrawRectangleCenteredAt(
                    sf::Vector2f(position.x * _cellSize.x + _border, position.y * _cellSize.y + _border),
                    sf::Color::Green
                );
            }

            if (cell.GetType() == mg::End) {
                DrawRectangleCenteredAt(
                    sf::Vector2f(position.x * _cellSize.x + _border, position.y * _cellSize.y + _border),
                    sf::Color::Red
                );
            }

            if (cell.GetWalls().top == mg::WallState::Close) {
                wallShape.setPosition(position.x * _cellSize.x + _border, position.y * _cellSize.y + _border);
                _window.draw(wallShape);
            }

            if (cell.GetWalls().right == mg::WallState::Close) {
                wallShape.setPosition((position.x + 1) * _cellSize.x + _border, position.y * _cellSize.y + _border);
                wallShape.rotate(90);
                _window.draw(wallShape);
                wallShape.rotate(-90);
            }

            if (cell.GetWalls().bottom == mg::WallState::Close) {
                wallShape.setPosition(position.x * _cellSize.x + _border, (position.y + 1) * _cellSize.y + _border);
                _window.draw(wallShape);
            }

            if (cell.GetWalls().left == mg::WallState::Close) {
                wallShape.setPosition(position.x * _cellSize.x + _border, position.y * _cellSize.y + _border);
                wallShape.rotate(90);
                _window.draw(wallShape);
                wallShape.rotate(-90);
            }
        }
    }

    _window.display();
}
