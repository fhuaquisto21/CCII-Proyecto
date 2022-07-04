#ifndef TESTSCENE_H
#define TESTSCENE_H

#include <SFML/Graphics.hpp>
#include "./Scene.h"
#include "./../../Object.Factory/Object/Character/Bob.Character.h"

class TestScene : public Scene
{
private:
public:
    TestScene();
    ~TestScene();
    void draw(sf::RenderWindow *);
    void events(sf::Event *);
};

#include "./Test.Scene.cpp"

#endif