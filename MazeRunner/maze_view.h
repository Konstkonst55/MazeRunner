#pragma once

#ifndef MAZE_VIEW_H
#define MAZE_VIEW_H

#include <vector>
#include <maze.h>
#include <SFML/Graphics.hpp>

namespace view {
	/// <summary>
	///  ласс дл€ отрисовки лабиринта
	/// <para> vector vector Cell maze - копи€ лабиринта </para>
	/// <para> RenderWindow window - окно дл€ рендера </para>
	/// <para> Color color = White - цвет границ </para>
	/// <para> size_t border = 10 - отступы лабиринта от границ окна </para>
	/// <para> size_t thickness = 2 - толщина стен </para>
	/// <para> Vector2f cellSize = { 20, 20 } - размер €чейки </para>
	/// </summary>
	class MazeView {
	private:
		mg::Maze& _maze;
		sf::RenderWindow& _window;
		std::vector<mg::data::Point>& _path;
		sf::Color _borderColor = sf::Color::White;
		sf::Color _pathColor = sf::Color::Green;
		size_t _border = 10;
		size_t _thickness = 2;
		sf::Vector2f _cellSize = { 20, 20 };

		void UpdateCellSize();
		void DrawRectangleCenteredAt(const sf::Vector2f& position, const sf::Color& color);

	public:
		MazeView() = default;
		MazeView(mg::Maze& maze, sf::RenderWindow& window, std::vector<mg::data::Point>& path, const sf::Color& borderColor = sf::Color::White, const sf::Color& pathColor = sf::Color::Green, size_t border = 10, size_t thickness = 2);
		~MazeView() = default;

		const size_t GetBorder() const;
		const size_t GetThickness() const;
		void SetMaze(const mg::Maze& maze);
		void SetPath(const std::vector<mg::data::Point>& path);
		void SetBorderColor(const sf::Color& borderColor);
		void SetPathColor(const sf::Color& pathColor);
		void SetBorder(size_t border);
		void SetThickness(size_t thickness);

		void Render();
		void RenderPath();
	};
}

#endif // MAZE_VIEW_H