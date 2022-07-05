#include <SFML/Graphics.hpp>
#include "./Camera.h"

Camera::Camera(sf::FloatRect _size)
{
    this->camera = new sf::View(_size);
}

Camera::~Camera() {}

void Camera::setFollow(Object *_obj)
{
    this->camera->setCenter(_obj->getPosition());
}

void Camera::events(sf::Event *_event)
{
    return;
}