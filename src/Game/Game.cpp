#include <SFML/Graphics.hpp>
//#include "./../Scene.Manager/Scene.Manager.h"
#include "./Game.h"

unsigned int const FPS = 60;
sf::Color *const BG_COLOR = new sf::Color(255, 255, 255, 255);

//Object *bobCharacter = ObjectFactory::getObject(gm::Object::BobCharacter);

Game::Game(sf::VideoMode *_size, std::string _name, int _styleScreen)
{
    this->size = _size;
    this->name = _name;
    this->styleScreen = _styleScreen;
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
    SceneManager::get()->push(this->window, gm::Scene::TestScene);
}

void Game::draw(sf::Event *event)
{
    this->window->clear(*BG_COLOR);
    SceneManager::get()->top()->draw();
    SceneManager::get()->top()->events(event);
    this->window->display();
}

void Game::close(sf::Event *event)
{
    while (this->window->pollEvent(*event))
    {
        if (event->type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::render()
{
    while (this->window->isOpen())
    {
        sf::Event *event = new sf::Event;
        this->close(event);
        this->draw(event);
    }
}