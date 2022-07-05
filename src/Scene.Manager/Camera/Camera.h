#ifndef CAMERA_H
#define CAMERA_H

#include <SFML/Graphics.hpp>

class Camera
{
private:
    sf::View *camera;

public:
    Camera(sf::FloatRect);
    ~Camera();
    void events(sf::Event *);
    void setFollow(Object *);
};

#include "./Camera.cpp"

#endif