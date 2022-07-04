#ifndef BOBCHARACTER_H
#define BOBCHARACTER_H

#include "./Character.h"

class BobCharacter : public Character
{
private:
public:
    BobCharacter();
    ~BobCharacter();
    void draw(sf::RenderWindow *);
    void events(sf::Event *);
};

#include "./Bob.Character.cpp"

#endif