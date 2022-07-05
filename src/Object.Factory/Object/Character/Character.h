#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>
#include "./../Object.h"

/**
 * @author Jhonathan 
 * @class Character
 */
class Character : public Object
{
private:
    float speed;
    int munition;
    sf::Vector2f *translate;

public:
    Character(std::string, float);
    ~Character();
    void move(sf::Event *);
    virtual void events(sf::Event *);
    virtual void draw(sf::RenderWindow *);
};

#include "./Character.cpp"

#endif