#ifndef SERVERPACKET_H
#define SERVERPACKET_H

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

struct ServerPacket
{
    std::string name;
    std::string instruction;
    sf::RenderWindow * value;
};

#include "./Server.Packet.cpp"

#endif
