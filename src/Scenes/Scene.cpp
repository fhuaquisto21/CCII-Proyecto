#include <SFML/Graphics.hpp>
#include <map>
#include "./../Headers/Scenes/Scene.h"

Scene::Scene(sf::RenderWindow *&window)
{
    this->scene = window;
    this->objects = new std::map<std::string, Object *>;
    this->states = new std::map<std::string, State *>;
}

Scene::~Scene() {}

void Scene::addObject(std::string _key, int _typeObject, int _object)
{
    std::pair<std::string, Object *> newObject(_key, ObjectFactory::getObject(_typeObject, _object));
    this->objects->insert(newObject);
}

sf::RenderWindow *Scene::getScene()
{
    return this->scene;
}
std::map<std::string, Object *> *Scene::getObjects()
{
    return this->objects;
}
std::map<std::string, State *> *Scene::getStates()
{
    return this->states;
}