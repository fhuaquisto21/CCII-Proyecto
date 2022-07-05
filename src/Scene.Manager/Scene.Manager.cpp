#include "./Scene.Manager.h"

SceneManager *SceneManager::sceneManager = nullptr;
//std::stack<Scene *> *SceneManager::scenes = new std::stack<Scene *>;

/*
SceneManager *SceneManager::get(sf::RenderWindow *_window)
{
    if (sceneManager == nullptr)
    {
        sceneManager = new SceneManager(_window);
    }
    return sceneManager;
}

SceneManager *SceneManager::get()
{
    return sceneManager;
}
SceneManager::SceneManager(sf::RenderWindow *_window)
{
    this->scenes->push(SceneFactory::getScene(_window, gm::Scene::TestScene));
}
*/

SceneManager::SceneManager(): scenes(new std::stack<Scene *>)
{
}

SceneManager *SceneManager::get() {
    if (sceneManager == nullptr) {
        sceneManager = new SceneManager();
    }
    return sceneManager;
}

void SceneManager::push(sf::RenderWindow *_window, int _scene)
{
    this->scenes->push(SceneFactory::getScene(_window, _scene));
}

void SceneManager::pop()
{
    this->scenes->pop();
}

Scene *SceneManager::top()
{
    return this->scenes->top();
}