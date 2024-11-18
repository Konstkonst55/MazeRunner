#include "maze_view.h"

#include <SFML/Graphics.hpp>
#include <kruskal_generator.h>
#include <maze_path_finder.h>
#include <string>

void Regenerate(mg::gen::MazeGenerator& mazeGenerator, mpf::MazePathFinder& mazePathFinder);
void Redraw(view::MazeView& mazeView);

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

    try {
        sf::RenderWindow window(sf::VideoMode(winWidth, winHeight), appName);
        mg::gen::KruskalMazeGenerator mazeGen(mg::data::MazeSize(mazeWidth, mazeHeight));
        mg::Maze& maze = mazeGen.GetMaze();
        maze.SetStart(start);
        maze.SetEnd(end);
        mazeGen.Generate();

        mpf::MazePathFinder mazePathFinder(maze);
        mazePathFinder.FindPath();
        std::vector<mg::data::Point>& path = mazePathFinder.GetPath();

        view::MazeView mazeView(maze, window, path, borderColor, pathColor, borderMargin, borderThickness);
        Redraw(mazeView);
        window.display();

        while (window.isOpen()) {
            sf::Event event;

            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }

                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::R) {
                        window.clear();
                        Regenerate(mazeGen, mazePathFinder);
                        Redraw(mazeView);
                        window.display();
                    }
                }

                if (event.type == sf::Event::Resized) {
                    window.clear();
                    Redraw(mazeView);
                    window.display();
                }
            }
        }
    }
    catch (const std::runtime_error& re) {
        std::cerr << re.what() << std::endl << std::endl;
        return 1;
    }
    catch (const std::out_of_range& our) {
        std::cerr << our.what() << std::endl << std::endl;
        return 1;
    }

    return 0;
}

void Regenerate(mg::gen::MazeGenerator& mazeGenerator, mpf::MazePathFinder& mazePathFinder) {
    mazeGenerator.Generate();
    mazePathFinder.FindPath();
}

void Redraw(view::MazeView& mazeView){
    mazeView.Render();
    mazeView.RenderPath();
}