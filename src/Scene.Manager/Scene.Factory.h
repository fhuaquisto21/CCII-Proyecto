#ifndef SCENEFACTORY_H
#define SCENEFACTORY_H

#include <SFML/Graphics.hpp>
#include "./Scene/Test.Scene.h"
#include "./Scene/None.Scene.h"

class SceneFactory
{
protected:
    SceneFactory();

public:
    SceneFactory(SceneFactory &_other) = delete;
    void operator=(const SceneFactory &) = delete;
    static Scene *getScene(sf::RenderWindow *, int);
};

#include "./Scene.Factory.cpp"

#endif