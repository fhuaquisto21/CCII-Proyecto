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

void Character::move(sf::Event *_event, sf::UdpSocket * _socket = nullptr)
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
    
    this->move(_event);
    //std::cout << this->translate->x << " " << this->translate->y << std::endl;
    //printf("\e[1;1H\e[2J");
    /*
    std::cout << _event->type << std::endl;
    std::cout << sf::Event::GainedFocus << std::endl;
    std::cout << sf::Event::LostFocus << std::endl;
    */
}

void Character::draw(sf::RenderWindow * _window) {
    _window->draw(*this->getSprite());
    this->collisions();
    
}

void Character::collisions(){
    if(this->getSprite()->getPosition().x < 30.f)
   {
        this->getSprite()->setPosition(30.f, this->getSprite()->getPosition().y);
   }

    if(this->getSprite()->getPosition().y < 50.f)
   {
        this->getSprite()->setPosition(this->getSprite()->getPosition().x, 50.f);
   }

   if(this->getSprite()->getPosition().x + this->getSprite()->getGlobalBounds().width > 830)
   {
        this->getSprite()->setPosition(830 - this->getSprite()->getGlobalBounds().width, this->getSprite()->getPosition().y);
   }

    if(this->getSprite()->getPosition().y + this->getSprite()->getGlobalBounds().height > 650 )
   {
        this->getSprite()->setPosition(this->getSprite()->getPosition().x,650  - this->getSprite()->getGlobalBounds().height);
   }
}