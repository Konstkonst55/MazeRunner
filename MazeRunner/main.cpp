
#include <SFML/Graphics.hpp>
#include <MazeGenerator.h>
#include "MazeView.h"
#include <random>

bool GetRandomBool();
mg::WallState SafeCastToWallState(bool);

int main() {
    const sf::Vector2f msize = { 30, 30 };
    sf::RenderWindow window(sf::VideoMode(500, 500), "MazeRunner");
    mg::MazeGenerator mazeGen(mg::MazeSize((unsigned int)msize.x, (unsigned int)msize.y));
    mazeGen.Generate();
    view::MazeView mazeView(mazeGen.GetMaze(), window);
    mazeView.Render();

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R) {
                window.clear();
                mazeGen.Generate();
                mazeView.SetMaze(mazeGen.GetMaze());
                mazeView.Render();
            }
            
            if (event.type == sf::Event::Resized) {
                window.clear();
                mazeView.Render();
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