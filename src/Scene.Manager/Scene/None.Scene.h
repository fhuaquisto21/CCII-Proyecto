#ifndef NONESCENE_H
#define NONESCENE_H

#include <SFML/Graphics.hpp>
#include "./Scene.h"

class NoneScene : public Scene
{
private:
public:
    NoneScene(sf::RenderWindow *);
    ~NoneScene();
    void draw();
    void events(sf::Event *);
};

#include "./None.Scene.cpp"

#endif