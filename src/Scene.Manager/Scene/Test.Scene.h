#ifndef TESTSCENE_H
#define TESTSCENE_H

#include <SFML/Graphics.hpp>
#include "./../Scene.Manager.h"
#include "./Scene.h"

class TestScene : public Scene
{
private:
public:
    TestScene(sf::RenderWindow *);
    ~TestScene();
    void draw();
    void events(sf::Event *);
};

#include "./Test.Scene.cpp"

#endif