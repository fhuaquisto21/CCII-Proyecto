#include <SFML/Graphics.hpp>
#include "./../Headers/Classes/Object.h"

Object::Object(std::string _name, std::string _type)
{
    this->name = _name;
    this->type = _type;
    this->sprite = new sf::Sprite;
    this->texture = new sf::Texture;
}

Object::~Object() {}

void Object::setPosition(sf::Vector2f _position)
{
    this->sprite->setPosition(_position);
}

sf::Vector2f Object::getPosition()
{
    return this->sprite->getPosition();
}

std::string Object::getName()
{
    return this->name;
}

std::string Object::getType()
{
    return this->type;
}

sf::Sprite *Object::getSprite()
{
    return this->sprite;
}

sf::Texture *Object::getTexture()
{
    return this->texture;
}

void Object::setTexture(std::string _urlImage)
{
    this->texture->loadFromFile(_urlImage);
}

void Object::setSprite()
{
    this->sprite->setTexture(*this->texture);
}