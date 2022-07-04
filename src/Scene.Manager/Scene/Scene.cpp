#include "./Scene.h"
#include "./../../Object.Factory/Object.Factory.h"

Scene::Scene()
{
    this->fState = new std::map<std::string, float>;
    this->bState = new std::map<std::string, bool>;
    this->sState = new std::map<std::string, std::string>;
}

Scene::~Scene() {}
/*
void Scene::addObject(std::string _key, int _object)
{
    Object *obj = ObjectFactory::getObject(_object);
    //std::pair<std::string, Object*> asd(_key, obj);
    //this->objects->insert(std::pair<std::string, Object>(_key, *obj));
    //this->addSState(_key, _key);
    //std::cout << this->getSState(_key) << std::endl;
}
*/
void Scene::addObject(std::string _key, int _object)
{
    Object *obj = ObjectFactory::getObject(_object);
    this->objects.insert(std::make_pair(_key, obj));
    //std::pair<std::string, Object*> asd(_key, obj);
    //this->objects->insert(std::pair<std::string, Object>(_key, *obj));
    //this->addSState(_key, _key);
    //std::cout << this->getSState(_key) << std::endl;
}

void Scene::addFState(std::string _key, float _value)
{
    this->fState->insert(std::pair<std::string, float>(_key, _value));
}

void Scene::addBState(std::string _key, bool _value)
{
    this->bState->insert(std::pair<std::string, bool>(_key, _value));
}

void Scene::addSState(std::string _key, std::string _value)
{
    this->sState->insert(std::pair<std::string, std::string>(_key, _value));
}

void Scene::updateFState(std::string _key, float _value)
{
    this->fState->at(_key) = _value;
}

void Scene::updateBState(std::string _key, bool _value)
{
    this->bState->at(_key) = _value;
}

void Scene::updateSState(std::string _key, std::string _value)
{
    this->sState->at(_key) = _value;
}
/*
Object *Scene::getObject(std::string _key)
{
    return &this->objects->at(_key);
}
*/
Object *Scene::getObject(std::string _key)
{
    return this->objects.at(_key);
}

float Scene::getFState(std::string _key)
{
    return this->fState->at(_key);
}

bool Scene::getBState(std::string _key)
{
    return this->bState->at(_key);
}

std::string Scene::getSState(std::string _key)
{
    return this->sState->at(_key);
}

void Scene::draw(sf::RenderWindow *_window) {}

void Scene::events(sf::Event *_event) {}