
#include <SFML/Graphics.hpp>
#include <MazeGenerator.h>
#include <MazePathFinder.h>
#include "MazeView.h"
#include <string>

void Regenerate(mg::MazeGenerator&, mpf::MazePathFinder&, view::MazeView&);
void Redraw(mg::MazeGenerator&, mpf::MazePathFinder&, view::MazeView&);

int main() {
    const std::string appName   = "Maze Runner";
    const sf::Color 
        borderColor             = sf::Color::White,
        pathColor               = sf::Color::Green;
    const unsigned int
        mazeWidth               = 20,
        mazeHeight              = 20,
        winWidth                = 800,
        winHeight               = 800,
        borderThickness         = 1,
        borderMargin            = 10;
    const mg::Point 
        start                   = mg::Point(0, 0),
        end                     = mg::Point(mazeHeight - 1, mazeWidth - 1);

    //const mg::Point
    //    start = mg::Point(2, 10),
    //    end = mg::Point(8, 5);

    sf::RenderWindow window(sf::VideoMode(winWidth, winHeight), appName);
    mg::MazeGenerator mazeGen(mg::MazeSize(mazeWidth, mazeHeight));
    mazeGen.SetStart(start);
    mazeGen.SetEnd(end);
    mazeGen.Generate();

    mpf::MazePathFinder mazePathFinder(mazeGen.GetMaze());
    mazePathFinder.FindPath();

    view::MazeView mazeView(mazeGen.GetMaze(), mazePathFinder.GetPath(), window, borderColor, pathColor, borderThickness, borderMargin);
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

    mazePathFinder.SetMaze(mazeGen.GetMaze());
    mazePathFinder.FindPath();

    mazeView.SetMaze(mazeGen.GetMaze());
    mazeView.SetPath(mazePathFinder.GetPath());
}

void Redraw(mg::MazeGenerator& mazeGen, mpf::MazePathFinder& mazePathFinder, view::MazeView& mazeView){
    mazeView.Render();
    mazeView.RenderPath();
}