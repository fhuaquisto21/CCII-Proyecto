#include <SFML/Graphics.hpp>
#include "../Headers/Classes/Game.h"

unsigned int const FPS = 60;
sf::Color *const BG_COLOR = new sf::Color(255, 255, 255, 255);

Game::Game(sf::VideoMode *_size, std::string _name, int _styleScreen)
{
    this->size = _size;
    this->name = _name;
    this->styleScreen = _styleScreen;
    //this->scenesManager = ScenesManager::GetInstance();
    switch (this->styleScreen)
    {
    case 0:
        this->window = new sf::RenderWindow(*this->size, this->name, sf::Style::Default);
        break;
    case 1:
        this->window = new sf::RenderWindow(sf::VideoMode(), this->name, sf::Style::Fullscreen);
        break;
    default:
        this->window = new sf::RenderWindow(*this->size, this->name, sf::Style::Default);
        break;
    }

    this->window->setFramerateLimit(FPS);
}

void Game::draw()
{
    //this->window->setView(this->scenesManager->value());
    this->window->clear(*BG_COLOR);
    this->window->display();
}

void Game::close(sf::Event &event)
{
    while (this->window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::render()
{
    while (this->window->isOpen())
    {
        sf::Event event;
        this->close(event);
        this->draw();
    }
}