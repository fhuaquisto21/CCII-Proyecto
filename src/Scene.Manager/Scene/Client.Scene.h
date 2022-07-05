#ifndef CLIENTSCENE_H
#define CLIENTSCENE_H

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "./../Scene.Manager.h"
#include "./Scene.h"

class ClientScene : public Scene
{
private:
    sf::TcpSocket *socket;
public:
    ClientScene(sf::RenderWindow *);
    ~ClientScene();
    void draw();
    void events(sf::Event *);
};

#include "./Client.Scene.cpp"

#endif