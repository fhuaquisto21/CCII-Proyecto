#ifndef SCENE_H
#define SCENE_H

#include <SFML/Graphics.hpp>
#include <map>
#include <vector>
#include "./../../Object.Factory/Object/Object.h"

class Scene
{
private:
    std::map<std::string, Object*> objects;
    //std::vector<Object*> objects;
    std::map<std::string, float> *fState;
    std::map<std::string, bool> *bState;
    std::map<std::string, std::string> *sState;

public:
    Scene();
    ~Scene();
    void addObject(std::string, int);
    //void addObject(int);
    void addFState(std::string, float);
    void addBState(std::string, bool);
    void addSState(std::string, std::string);
    void updateFState(std::string, float);
    void updateBState(std::string, bool);
    void updateSState(std::string, std::string);
    Object *getObject(std::string);
    //Object *getObject(int);
    float getFState(std::string);
    bool getBState(std::string);
    std::string getSState(std::string);
    virtual void draw(sf::RenderWindow *);
    virtual void events(sf::Event *);
};

#include "./Scene.cpp"

#endif