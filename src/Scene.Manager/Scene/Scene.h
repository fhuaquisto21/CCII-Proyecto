#ifndef SCENE_H
#define SCENE_H

#include <SFML/Graphics.hpp>
#include <map>
#include <vector>
#include "./../Scene.Manager.h"
#include "./../../Object.Factory/Object.Factory.h"
#include "./../../Object.Factory/Object/Object.h"
#include "./../Camera/Camera.h"

class Scene
{
private:
    sf::RenderWindow * window;
    std::map<std::string, Object *> objects;
    std::map<std::string, Camera *> cameras;
    std::map<std::string, float> *fState;
    std::map<std::string, bool> *bState;
    std::map<std::string, std::string> *sState;
    std::string mode;

public:
    Scene(std::string, sf::RenderWindow *);
    ~Scene();
    void addObject(std::string, int);
    void addCamera(std::string, sf::FloatRect);
    void addFState(std::string, float);
    void addBState(std::string, bool);
    void addSState(std::string, std::string);
    void updateFState(std::string, float);
    void updateBState(std::string, bool);
    void updateSState(std::string, std::string);
    Object *getObject(std::string);
    float getFState(std::string);
    bool getBState(std::string);
    std::string getSState(std::string);
    std::string getMode();
    sf::RenderWindow *getWindow();
    virtual void draw();
    virtual void events(sf::Event *);
};

namespace gm {
    namespace Scene {
        enum {
            TestScene = 0,
            NoneScene = 1,
            ServerScene = 2,
            ClientScene = 3,
        };
    }
}

#include "./Scene.cpp"

#endif