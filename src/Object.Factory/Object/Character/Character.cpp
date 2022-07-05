#include <iostream>
#include <math.h>
#include "./Character.h"

Character::Character(std::string _mode, std::string _name, float _speed) : Object(_mode, "Character", _name)
{
    this->speed = _speed;
    this->munition = 5;
    this->translate = new sf::Vector2f;
}

Character::~Character() {}

void Character::moveServer() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->translate->y -= this->speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->translate->y += this->speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->translate->x -= this->speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->translate->x += this->speed;
}

void Character::moveClient() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->translate->y -= this->speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->translate->y += this->speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->translate->x -= this->speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->translate->x += this->speed;
}

void Character::move(sf::Event *_event)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->translate->y -= this->speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->translate->y += this->speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->translate->x -= this->speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->translate->x += this->speed;

    if (this->translate->x != 0.f || this->translate->y != 0.f)
        *this->translate /= std::sqrt(2.f);

    this->getSprite()->move(*this->translate);
}

void Character::events(sf::Event *_event)
{
    
    this->move(new sf::Event);
    //std::cout << this->translate->x << " " << this->translate->y << std::endl;
    //printf("\e[1;1H\e[2J");
}

void Character::draw(sf::RenderWindow * _window) {
    _window->draw(*this->getSprite());
    
}