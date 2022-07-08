#ifndef NETWROK_H
#define NETWROK_H

#include <SFML/Network.hpp>

class Network {
    private:
        sf::UdpSocket *socket;
    public:
        Network();
        ~Network();
        sf::UdpSocket *getSocket();
};

#include "./Network.cpp"

#endif