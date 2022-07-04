#include <SFML/Graphics.hpp>
#include "./Game.h"
#include "./../Object.Factory/Object/Character/Bob.Character.h"
#include "./../Object.Factory/Object.Factory.h"
#include "./../Scene.Manager/Scene/Test.Scene.h"

unsigned int const FPS = 60;
sf::Color *const BG_COLOR = new sf::Color(255, 255, 255, 255);

//Object *bobCharacter = ObjectFactory::getObject(gm::Object::BobCharacter);
Scene *scenet = new TestScene;

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
}

void Game::draw(sf::Event &event)
{
    this->window->clear(*BG_COLOR);
    scenet->draw(this->window);
    scenet->events(&event);
    //bobCharacter->draw(this->window);
    //bobCharacter->events(&event);
    //this->window->draw(*bobCharacter->getSprite());
    /*
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Up)
            bobCharacter->move(sf::Keyboard::Up);
        if (event.key.code == sf::Keyboard::Down)
            bobCharacter->move(sf::Keyboard::Down);
        if (event.key.code == sf::Keyboard::Left)
            bobCharacter->move(sf::Keyboard::Left);
        if (event.key.code == sf::Keyboard::Right)
            bobCharacter->move(sf::Keyboard::Right);
    }
    */
    
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
        this->draw(event);
    }
}