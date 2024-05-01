#pragma once

#ifndef MAZE_VIEW_H
#define MAZE_VIEW_H

#include <vector>
#include <Cell.h>
#include <SFML/Graphics.hpp>

namespace view {
	class MazeView {
	private:
		std::vector<std::vector<mg::Cell>> _maze;
		sf::RenderWindow& _window;
		sf::Color _color = sf::Color::White;
		size_t _border = 10;
		size_t _thickness = 2;
		
		sf::Vector2f _cellSize = { 20, 20 };

		void UpdateCellSize();
		void DrawRectangleCenteredAt(sf::Vector2f, sf::Color);
	public:
		MazeView(std::vector<std::vector<mg::Cell>>, sf::RenderWindow&);
		MazeView(std::vector<std::vector<mg::Cell>>, sf::RenderWindow&, sf::Color);
		MazeView(std::vector<std::vector<mg::Cell>>, sf::RenderWindow&, sf::Color, size_t);
		MazeView(std::vector<std::vector<mg::Cell>>, sf::RenderWindow&, sf::Color, size_t, size_t);
		
		void SetMaze(std::vector<std::vector<mg::Cell>>);
		void SetColor(sf::Color);
		void SetBorder(size_t);
		size_t GetBorder();
		void SetThickness(size_t);
		size_t GetThickness();
		
		void Render();
	};
}

#endif // MAZE_VIEW_H