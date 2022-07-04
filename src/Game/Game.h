#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

class Game
{
private:
    sf::RenderWindow *window;
    sf::VideoMode *size;
    std::string name;
    int styleScreen;
    int scene;

public:
    Game(sf::VideoMode *, std::string, int);
    ~Game();
    void render();
    void draw(sf::Event &);
    void close(sf::Event&);
};

#include "./Game.cpp"

#endif