#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <SFML/Graphics.hpp>
#include <stack>
#include "./Scene/Scene.h"


class SceneManager
{
protected:
    // SceneManager(sf::RenderWindow *);
    SceneManager();
    std::stack<Scene *> *scenes;
    static SceneManager *sceneManager;

public:
    SceneManager(SceneManager &_other) = delete;
    void operator=(const SceneManager &) = delete;
    // static SceneManager *get(sf::RenderWindow *);
    static SceneManager *get();
    Scene *top();
    void push(sf::RenderWindow *, int);
    void pop();
    void home();
};
#include "./Scene.Factory.h"

#include "./Scene.Manager.cpp"

#endif