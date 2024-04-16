#pragma once

#ifndef MAZE_VIEW_H
#define MAZE_VIEW_H

#include <vector>
#include <Cell.h>
#include <SFML/Graphics.hpp>

namespace view {
	void Render(std::vector<std::vector<Cell>>, sf::RenderWindow&, const int = 10);
}

#endif // MAZE_VIEW_H