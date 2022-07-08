#include "./Network.h"

Network::Network() {
    this->socket = new sf::UdpSocket;
}

Network::~Network() {}

sf::UdpSocket *Network::getSocket() {
    return this->socket;
}