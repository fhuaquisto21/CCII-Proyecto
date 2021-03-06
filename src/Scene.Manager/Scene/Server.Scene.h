#ifndef SERVERSCENE_H
#define SERVERSCENE_H

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "./../Scene.Manager.h"
#include "./Scene.h"

class ServerScene : public Scene
{
private:
    sf::UdpSocket *socket;
    std::vector<sf::IpAddress> ips;
    std::vector<int> ports;
public:
    ServerScene(sf::RenderWindow *);
    ~ServerScene();
    void draw();
    void events(sf::Event *);
};

#include "./Server.Scene.cpp"

#endif