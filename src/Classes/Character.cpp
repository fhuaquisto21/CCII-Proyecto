#include <SFML/Graphics.hpp>
#include <stack>
#include "./../Headers/Classes/Character.h"

Character::Character(std::string _name, float _speed): Object(_name, "Character") {
    this->speed = _speed;
}

/*
void Character::pushTrash()
{

}

void Character::popTrash()
{

}

void Character::move(int _direction)
{
    switch (_direction)
    {
    case 1:
        this->moveUp();
        break;
    case 2:
        this->moveDown();
        break;
    case 3:
        this->moveLeft();
        break;
    case 4:
        this->moveRight();
        break;
    
    default:
        break;
    }
}

void Character::moveUp()
{
    this->characterSprite->move(this->getCharacterPosicionX(),this->getCharacterPosicionY()-this->speed);
}

void Character::moveDown()
{
    this->characterSprite->move(this->getCharacterPosicionX(),this->getCharacterPosicionY()+this->speed);
}

void Character::moveLeft()
{
    this->characterSprite->move(this->getCharacterPosicionX()-this->speed,this->getCharacterPosicionY());
}

void Character::moveRight()
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
*/