#include <iostream>
#include <math.h>
#include "./Character.h"

Character::Character(std::string _name, float _speed) : Object(_name, "Character")
{
    this->speed = _speed;
    this->munition = 5;
    this->translate = new sf::Vector2f;
}

Character::~Character() {}

void Character::move(sf::Event *_event)
{
    if (this->translate->x != 0.f || this->translate->y != 0.f)
        *this->translate /= std::sqrt(2.f);

    this->getSprite()->move(*this->translate);
}

void Character::events(sf::Event *_event)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        this->translate->y -= this->speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        this->translate->y += this->speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        this->translate->x -= this->speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        this->translate->x += this->speed;
    std::cout << this->translate->x << " " << this->translate->y << std::endl;
    printf("\e[1;1H\e[2J");
}

void Character::draw(sf::RenderWindow * _window) {
    _window->draw(*this->getSprite());
    this->move(new sf::Event);
    
}