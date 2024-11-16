#include <SFML/Graphics.hpp>
#include <maze_generator.h>
#include <maze_path_finder.h>
#include "maze_view.h"
#include <string>

void Regenerate(mg::MazeGenerator&, mpf::MazePathFinder&, view::MazeView&);
void Redraw(mg::MazeGenerator&, mpf::MazePathFinder&, view::MazeView&);

int main() {
    const std::string appName   = "Maze Runner";
    const sf::Color 
        borderColor             = sf::Color::White,
        pathColor               = sf::Color::Green;
    const size_t 
        mazeWidth               = 30u,
        mazeHeight              = 30u,
        winWidth                = 800u,
        winHeight               = 800u,
        borderThickness         = 1u,
        borderMargin            = 10u;
    const mg::data::Point 
        start                   = mg::data::Point(0, 0),
        end                     = mg::data::Point(static_cast<int>(mazeHeight - 1), static_cast<int>(mazeWidth - 1));

    sf::RenderWindow window(sf::VideoMode(winWidth, winHeight), appName);
    mg::MazeGenerator mazeGen(mg::data::MazeSize(mazeWidth, mazeHeight));
    mazeGen.SetStart(start);
    mazeGen.SetEnd(end);
    mazeGen.Generate();
    auto maze = mazeGen.GetMaze();

    mpf::MazePathFinder mazePathFinder(maze);
    mazePathFinder.FindPath();
    auto path = mazePathFinder.GetPath();

    view::MazeView mazeView(maze, window, path, borderColor, pathColor, borderMargin, borderThickness);
    Redraw(mazeGen, mazePathFinder, mazeView);
    window.display();

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R) {
                window.clear();
                Regenerate(mazeGen, mazePathFinder, mazeView);
                Redraw(mazeGen, mazePathFinder, mazeView);
                window.display();
            }

            if (event.type == sf::Event::Resized) {
                window.clear();
                Redraw(mazeGen, mazePathFinder, mazeView);
                window.display();
            }
        }
    }

    return 0;
}

void Regenerate(mg::MazeGenerator& mazeGen, mpf::MazePathFinder& mazePathFinder, view::MazeView& mazeView) {
    mazeGen.Generate();
    auto maze = mazeGen.GetMaze();
    mazePathFinder.SetMaze(maze);

    mazePathFinder.FindPath();
    auto path = mazePathFinder.GetPath();

    mazeView.SetMaze(maze);
    mazeView.SetPath(path);
}

void Redraw(mg::MazeGenerator& mazeGen, mpf::MazePathFinder& mazePathFinder, view::MazeView& mazeView){
    mazeView.Render();
    mazeView.RenderPath();
}