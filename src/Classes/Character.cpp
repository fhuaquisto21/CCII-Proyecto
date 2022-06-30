#include <SFML/Graphics.hpp>
#include "./../Headers/Classes/Character.h"
#include <stack>

Character::Character(std::string _name,float _speed)
{
    this->name = _name;
    this->speed = _speed;
    this->trash = new std::stack <int> ();
    this->characterTexture = new sf::Texture;
    this->characterSprite = new sf::Sprite;
    this->characterTexture->loadFromFile("./src/Assets/Textures/jugador2a.png");
    this->characterSprite->setTexture(*this->characterTexture);
}

void Character::pushTrash()
{

}

void Character::popTrash()
{

}

void Character::mov(int _direction)
{
    switch (_direction)
    {
    case 1:
        this->movUp();
        break;
    case 2:
        this->movDown();
        break;
    case 3:
        this->movLeft();
        break;
    case 4:
        this->movRight();
        break;
    
    default:
        break;
    }
}

void Character::movUp()
{
    this->characterSprite->move(this->getCharacterPosicionX(),this->getCharacterPosicionY()-this->speed);
}

void Character::movDown()
{
    this->characterSprite->move(this->getCharacterPosicionX(),this->getCharacterPosicionY()+this->speed);
}

void Character::movLeft()
{
    this->characterSprite->move(this->getCharacterPosicionX()-this->speed,this->getCharacterPosicionY());
}

void Character::movRight()
{
    this->characterSprite->move(this->getCharacterPosicionX()+this->speed,this->getCharacterPosicionY());
}

float Character::getCharacterPosicionX()
{
    return this->characterSprite->getPosition().x;
}

float Character::getCharacterPosicionY()
{
    return this->characterSprite->getPosition().y;
}

sf::Sprite Character::getCharacterSprite()
{
    return *this->characterSprite;
}