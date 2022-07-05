#ifndef PLAYERPACKET_H
#define PLAYERPACKET_H

#include <SFML/Network.hpp>

struct PlayerPacket
{
    std::string name;
    std::string instruction;
    int value;
};

#include "./Player.Packet.cpp"

#endif
