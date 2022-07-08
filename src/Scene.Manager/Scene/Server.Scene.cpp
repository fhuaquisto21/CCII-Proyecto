#include "./Server.Scene.h"

ServerScene::ServerScene(sf::RenderWindow *_window) : Scene("server", _window)
{
    // std::string h = "Main Character";
    this->socket = new sf::UdpSocket;
    this->socket->setBlocking(false);
    this->socket->bind(3001);
    //std::cout << sf::IpAddress::getPublicAddress().toString() << std::endl;
    std::cout << this->getMode() << std::endl;
    this->addObject(this->getMode(), "player_1_character", gm::Object::BobCharacter);
    this->addObject(this->getMode(), "player_2_character", gm::Object::BobCharacter);
    this->addObject(this->getMode(), "player_3_character", gm::Object::BobCharacter);
    this->addObject(this->getMode(), "player_4_character", gm::Object::BobCharacter);
    // this->addObject("player_2_character", gm::Object::BobCharacter);
    // this->addCamera("player_1_camera", sf::FloatRect(0.f, 0.f, (float)(_window->getSize().x), (float)(_window->getSize().y)));
    // this->getObject("Main Character");
}

ServerScene::~ServerScene() {}

void ServerScene::draw()
{
    //sf::View vpersona = sf::View(sf::FloatRect(0.f, 0.f, (float)(this->getWindow()->getSize().x), (float)(this->getWindow()->getSize().y)));
    // vpersona.setCenter(this->getObject("Main Character")->getPosition());
    // vpersona.move();
    //_window->setView(vpersona);
    //std::cout << "Test" << std::endl;
    sf::Packet in;
    sf::IpAddress sender;
    unsigned short senderPort;
    if (this->socket->receive(in, sender, senderPort) == sf::Socket::Done) {
        std::string type;
        in >> type;
        if (type == "connect") {
            this->ips.push_back(sender);
            this->ports.push_back(senderPort);
            sf::Packet outa;
            std::string type = "select_character";
            int i = this->ips.size();
            outa << type << i;
            this->socket->send(outa, sender, senderPort);
        } else if (type == "move_character_1") {
            std::cout << "Move Character 1" << std::endl;
            float x, y;
            in >> x >> y;
            sf::Vector2f move(x, y);
            //std::cout << x << ":" << y << std::endl;
            this->getObject("player_1_character")->getSprite()->move(move);
        } else if (type == "move_character_2") {
            std::cout << "Move Character 2" << std::endl;
            float x, y;
            in >> x >> y;
            sf::Vector2f move(x, y);
            //std::cout << x << ":" << y << std::endl;
            this->getObject("player_2_character")->getSprite()->move(move);
        } else if (type == "move_character_3") {
            std::cout << "Move Character 3" << std::endl;
            float x, y;
            in >> x >> y;
            sf::Vector2f move(x, y);
            //std::cout << x << ":" << y << std::endl;
            this->getObject("player_3_character")->getSprite()->move(move);
        } else if (type == "move_character_4") {
            std::cout << "Move Character 2" << std::endl;
            float x, y;
            in >> x >> y;
            sf::Vector2f move(x, y);
            //std::cout << x << ":" << y << std::endl;
            this->getObject("player_4_character")->getSprite()->move(move);
        }
    }

    sf::Packet out1, out2, out3, out4;
    //std::cout << "Test" << std::endl;
    std::string type1 = "render_characters";
    /*
    std::string type2 = "render_characters_2";
    std::string type3 = "render_characters_3";
    std::string type4 = "render_characters_4";
    */
    //std::cout << "Test" << std::endl;
    out1 << type1 << this->getObject("player_1_character")->getPosition().x << this->getObject("player_1_character")->getPosition().y << this->getObject("player_2_character")->getPosition().x << this->getObject("player_2_character")->getPosition().y << this->getObject("player_3_character")->getPosition().x << this->getObject("player_3_character")->getPosition().y << this->getObject("player_4_character")->getPosition().x << this->getObject("player_4_character")->getPosition().y;
    /*
    out2 << type2 << this->getObject("player_2_character")->getPosition().x << this->getObject("player_2_character")->getPosition().y;
    out3 << type3 << this->getObject("player_3_character")->getPosition().x << this->getObject("player_3_character")->getPosition().y;
    out4 << type4 << this->getObject("player_4_character")->getPosition().x << this->getObject("player_4_character")->getPosition().y;
    */
    //this->getObject("player_1_character")->draw(this->getWindow());
    //std::cout << "Test" << std::endl;
    for (int i = 0; i < this->ips.size(); ++i) {
        this->socket->send(out1, this->ips[i], this->ports[i]);
        /*
        this->socket->send(out2, this->ips[i], this->ports[i]);
        this->socket->send(out3, this->ips[i], this->ports[i]);
        this->socket->send(out3, this->ips[i], this->ports[i]);
        */
    }
    

    //this->getObject("player_1_character")->draw(this->getWindow());
    // this->getObject("Second Character")->draw(_window);
}

void ServerScene::events(sf::Event *_event)
{
    //this->getObject("player_1_character")->events(_event);
}