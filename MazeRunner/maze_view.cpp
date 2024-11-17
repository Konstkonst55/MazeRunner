#include "maze_view.h"

#include <iostream>

#pragma region MazeViewConstructor

view::MazeView::MazeView(mg::Maze& maze, sf::RenderWindow& window, std::vector<mg::data::Point>& path, const sf::Color& borderColor, const sf::Color& pathColor, size_t border, size_t thickness)
    : _maze(maze), _window(window), _path(path), _borderColor(borderColor), _pathColor(pathColor), _border(border), _thickness(thickness) {
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

void view::MazeView::SetMaze(const mg::Maze& maze) {
    _maze = maze;
    UpdateCellSize();
}

void view::MazeView::SetPath(const std::vector<mg::data::Point>& path) {
    _path = path;
    UpdateCellSize();
}

void view::MazeView::SetBorderColor(const sf::Color& borderColor) {
    _borderColor = borderColor;
}

void view::MazeView::SetPathColor(const sf::Color& pathColor) {
    _pathColor = pathColor;
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
        ((float)_window.getSize().y - _border * 2) / (float)_maze.GetMaze().size()
    };
}

/// <summary>
/// Отрисовка прямоугольника c координатами position и цветом color
/// </summary>
/// <param name="position"> - позиция</param>
/// <param name="color"> - цвет</param>
void view::MazeView::DrawRectangleCenteredAt(const sf::Vector2f& position, const sf::Color& color) {
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

    for (size_t row = 0; row < _maze.GetMaze().size(); row++) {
        for (size_t col = 0; col < _maze[0].size(); col++) {
            const auto& cell = _maze[row][col];
            sf::Vector2f position(col, row);

            if (position == sf::Vector2f((float)_maze.GetStart().x, (float)_maze.GetStart().y)) {
                DrawRectangleCenteredAt(sf::Vector2f(position.y * _cellSize.y + _border, position.x * _cellSize.x + _border), sf::Color::Green);
            }

            if (position == sf::Vector2f((float)_maze.GetEnd().x, (float)_maze.GetEnd().y)) {
                DrawRectangleCenteredAt(sf::Vector2f(position.y * _cellSize.y + _border, position.x * _cellSize.x + _border), sf::Color::Red);
            }

            if (cell.GetWalls().top == mg::data::WallState::Close) {
                wallShape.setPosition(position.x * _cellSize.x + _border, position.y * _cellSize.y + _border);
                _window.draw(wallShape);
            }

            if (cell.GetWalls().right == mg::data::WallState::Close) {
                wallShape.setPosition((position.x + 1) * _cellSize.x + _border, position.y * _cellSize.y + _border);
                wallShape.rotate(90);
                _window.draw(wallShape);
                wallShape.rotate(-90);
            }

            if (cell.GetWalls().bottom == mg::data::WallState::Close) {
                wallShape.setPosition(position.x * _cellSize.x + _border, (position.y + 1) * _cellSize.y + _border);
                _window.draw(wallShape);
            }

            if (cell.GetWalls().left == mg::data::WallState::Close) {
                wallShape.setPosition(position.x * _cellSize.x + _border, position.y * _cellSize.y + _border);
                wallShape.rotate(90);
                _window.draw(wallShape);
                wallShape.rotate(-90);
            }
        }
    }
}

/// <summary>
/// Отрисовка пути
/// </summary>
void view::MazeView::RenderPath() {
    if (_path.empty()) return;
    
    sf::VertexArray line(sf::PrimitiveType::LinesStrip, _path.size());

    for (size_t i = 0; i < _path.size(); i++) {
        line[i].position = sf::Vector2f((float)(_path[i].y * _cellSize.y + _border + _cellSize.y / 2), (float)(_path[i].x * _cellSize.x + _border + _cellSize.x / 2));
        line[i].color = _pathColor;
    }

    _window.draw(line);
}

#pragma endregion