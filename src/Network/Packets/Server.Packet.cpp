#include "./Server.Packet.h"

sf::Packet& operator <<(sf::Packet& packet, const ServerPacket& m)
{
    return packet << m.name << m.instruction << m.value;
}
sf::Packet& operator >>(sf::Packet& packet, ServerPacket& m)
{
    return packet >> m.name >> m.instruction >> m.value;
}