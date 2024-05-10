#pragma once

#ifndef MAZE_VIEW_H
#define MAZE_VIEW_H

#include <vector>
#include <Cell.h>
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
		std::vector<std::vector<mg::Cell>> _maze;
		std::vector<mg::Point> _path;
		sf::RenderWindow& _window;
		sf::Color _borderColor = sf::Color::White;
		sf::Color _pathColor = sf::Color::Green;
		size_t _border = 10;
		size_t _thickness = 2;
		sf::Vector2f _cellSize = { 20, 20 };

		void UpdateCellSize();
		void DrawRectangleCenteredAt(sf::Vector2f, sf::Color);

	public:
		MazeView(std::vector<std::vector<mg::Cell>>, sf::RenderWindow&);
		MazeView(std::vector<std::vector<mg::Cell>>, std::vector<mg::Point>, sf::RenderWindow&);
		MazeView(std::vector<std::vector<mg::Cell>>, std::vector<mg::Point>, sf::RenderWindow&, sf::Color);
		MazeView(std::vector<std::vector<mg::Cell>>, std::vector<mg::Point>, sf::RenderWindow&, sf::Color, sf::Color);
		MazeView(std::vector<std::vector<mg::Cell>>, std::vector<mg::Point>, sf::RenderWindow&, sf::Color, sf::Color, size_t);
		MazeView(std::vector<std::vector<mg::Cell>>, std::vector<mg::Point>, sf::RenderWindow&, sf::Color, sf::Color, size_t, size_t);

		const size_t GetBorder() const;
		const size_t GetThickness() const;
		void SetMaze(std::vector<std::vector<mg::Cell>>);
		void SetPath(std::vector<mg::Point>);
		void SetBorderColor(sf::Color);
		void SetPathColor(sf::Color);
		void SetBorder(size_t);
		void SetThickness(size_t);

		void Render();
		void RenderPath();
	};
}

#endif // MAZE_VIEW_H