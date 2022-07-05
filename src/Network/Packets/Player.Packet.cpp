#include "./Player.Packet.h"

PlayerPacket::PlayerPacket() {}
PlayerPacket::~PlayerPacket() {}

sf::Packet& operator <<(sf::Packet& packet, const PlayerPacket& m)
{
    return packet << m.name << m.instruction << m.value;
}
sf::Packet& operator >>(sf::Packet& packet, PlayerPacket& m)
{
    return packet >> m.name >> m.instruction >> m.value;
}