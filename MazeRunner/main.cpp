
#include <SFML/Graphics.hpp>
#include <MazeGenerator.h>
#include <MazePathFinder.h>
#include "MazeView.h"
#include <random>

bool GetRandomBool();
mg::WallState SafeCastToWallState(bool);
void Regenerate(mg::MazeGenerator&, mpf::MazePathFinder&, view::MazeView&);
void Redraw(mg::MazeGenerator&, mpf::MazePathFinder&, view::MazeView&);

int main() {
    const unsigned int
        mazeWidth   = 30,
        mazeHeight  = 30,
        winWidth    = 500,
        winHeight   = 500;

    sf::RenderWindow window(sf::VideoMode(winWidth, winHeight), "MazeRunner");
    mg::MazeGenerator mazeGen(mg::MazeSize(mazeWidth, mazeHeight));
    mazeGen.Generate();
    mpf::MazePathFinder mazePathFinder(mazeGen.GetMaze());
    mazePathFinder.FindPath();
    view::MazeView mazeView(mazeGen.GetMaze(), mazePathFinder.GetPath(), window);
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

bool GetRandomBool() {
    static std::default_random_engine generator(std::random_device{}());
    std::uniform_int_distribution<int> distribution(0, 1);
    return distribution(generator);
}

mg::WallState SafeCastToWallState(bool value) {
    return value ? mg::WallState::Open : mg::WallState::Close;
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