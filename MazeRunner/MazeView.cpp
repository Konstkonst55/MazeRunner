
#include "MazeView.h"
#include <iostream>

#pragma region MazeViewConstructor

view::MazeView::MazeView(std::vector<std::vector<mg::Cell>> maze, sf::RenderWindow& window)
    : MazeView(maze, {}, window, sf::Color::White) { }

view::MazeView::MazeView(std::vector<std::vector<mg::Cell>> maze, std::vector<mg::Point> path, sf::RenderWindow& window)
    : MazeView(maze, path, window, sf::Color::White) { }

view::MazeView::MazeView(std::vector<std::vector<mg::Cell>> maze, std::vector<mg::Point> path, sf::RenderWindow& window, sf::Color bColor)
    : MazeView(maze, path, window, bColor, sf::Color::Green, 2) { }

view::MazeView::MazeView(std::vector<std::vector<mg::Cell>> maze, std::vector<mg::Point> path, sf::RenderWindow& window, sf::Color bColor, sf::Color pColor)
    : MazeView(maze, path, window, bColor, pColor, 2) { }

view::MazeView::MazeView(std::vector<std::vector<mg::Cell>> maze, std::vector<mg::Point> path, sf::RenderWindow& window, sf::Color bColor, sf::Color pColor, size_t thickness)
    : MazeView(maze, path, window, bColor, pColor, thickness, 10) { }

view::MazeView::MazeView(std::vector<std::vector<mg::Cell>> maze, std::vector<mg::Point> path, sf::RenderWindow& window, sf::Color bColor, sf::Color pColor, size_t thickness, size_t border)
    : _maze(maze), _path(path), _window(window), _borderColor(bColor), _pathColor(pColor), _thickness(thickness), _border(border) {
    UpdateCellSize();
}

#pragma endregion

#pragma region MazeViewGetSet

const size_t view::MazeView::GetBorder() const {
    return _border;
}

const size_t view::MazeView::GetThickness() const {
    return _thickness;
}

void view::MazeView::SetMaze(std::vector<std::vector<mg::Cell>> maze) {
    _maze = maze;
}

void view::MazeView::SetPath(std::vector<mg::Point> path) {
    _path = path;
}

void view::MazeView::SetBorderColor(sf::Color color) {
    _borderColor = color;
}

void view::MazeView::SetPathColor(sf::Color color) {
    _pathColor = color;
}

void view::MazeView::SetBorder(size_t border) {
    _border = border;
}

void view::MazeView::SetThickness(size_t thickness) {
    _thickness = thickness;
}

#pragma endregion

#pragma region MazeViewLogic

/// <summary>
/// Вычисление расчета размера одной ячейки в зависимости от размера окна
/// </summary>
void view::MazeView::UpdateCellSize() {
    _cellSize = {
        ((float)_window.getSize().x - _border * 2) / (float)_maze[0].size(),
        ((float)_window.getSize().y - _border * 2) / (float)_maze.size()
    };
}

/// <summary>
/// Отрисовка прямоугольника c координатами position и цветом color
/// </summary>
/// <param name="position"> - позиция</param>
/// <param name="color"> - цвет</param>
void view::MazeView::DrawRectangleCenteredAt(sf::Vector2f position, sf::Color color) {
    sf::RectangleShape rectangle(sf::Vector2f(_cellSize.x, _cellSize.y));

    rectangle.setPosition(position.x, position.y);
    rectangle.setFillColor(color);

    _window.draw(rectangle);
}

/// <summary>
/// Отрисовка лабиринта
/// </summary>
void view::MazeView::Render() {
    sf::RectangleShape wallShape(sf::Vector2f(_cellSize.x, (float)_thickness));
    wallShape.setFillColor(_borderColor);

    for (const auto& row : _maze) {
        for (const auto& cell : row) {
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
}

void view::MazeView::RenderPath() {
    if (_path.empty()) return;

    sf::VertexArray line(sf::LinesStrip, _path.size());

    for (size_t i = 0; i < _path.size(); ++i) {
        line[i].position = sf::Vector2f((float)(_path[i].x * _cellSize.x + _border + _cellSize.x / 2),
            (float)(_path[i].y * _cellSize.y + _border + _cellSize.y / 2));
        line[i].color = _pathColor;
    }

    _window.draw(line);
}

#pragma endregion