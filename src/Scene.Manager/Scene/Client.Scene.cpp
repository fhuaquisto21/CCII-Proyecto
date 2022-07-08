#include "./Client.Scene.h"

ClientScene::ClientScene(sf::RenderWindow *_window) : Scene("client", _window)
{
    // std::string h = "Main Character";
    this->socket = new sf::UdpSocket;
    this->socket->setBlocking(false);
    std::string type = "connect";
    sf::Packet out;
    out << type;
    this->socket->send(out, "127.0.0.1", 3001);
    this->addObject(this->getMode(), "player_1_character", gm::Object::BobCharacter);
    this->addObject(this->getMode(), "player_2_character", gm::Object::BobCharacter);
    this->addObject(this->getMode(), "player_3_character", gm::Object::BobCharacter);
    this->addObject(this->getMode(), "player_4_character", gm::Object::BobCharacter);
    std::cout << this->getMode() << std::endl;
    // this->addObject("player_2_character", gm::Object::BobCharacter);
    // this->addCamera("player_1_camera", sf::FloatRect(0.f, 0.f, (float)(_window->getSize().x), (float)(_window->getSize().y)));
    // this->getObject("Main Character");
}

ClientScene::~ClientScene() {}

int character = 0;

void ClientScene::draw()
{
    //sf::View vpersona = sf::View(sf::FloatRect(0.f, 0.f, (float)(this->getWindow()->getSize().x), (float)(this->getWindow()->getSize().y)));
    // vpersona.setCenter(this->getObject("Main Character")->getPosition());
    // vpersona.move();
    //_window->setView(vpersona);
    
    sf::Packet in;
    sf::IpAddress sender;
    unsigned short senderPort;
    std::string type;
    if (this->socket->receive(in, sender, senderPort) == sf::Socket::Done) {
        in >> type;
        if (type == "render_characters") {
            //std::cout << "Receive" << std::endl;
            float p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y;
            in >> p1x >> p1y >> p2x >> p2y >> p3x >> p3y >> p4x >> p4y;
            sf::Vector2f move1(p1x, p1y);
            sf::Vector2f move2(p2x, p2y);
            sf::Vector2f move3(p3x, p3y);
            sf::Vector2f move4(p4x, p4y);
            this->getObject("player_1_character")->setPosition(move1);
            this->getObject("player_2_character")->setPosition(move2);
            this->getObject("player_3_character")->setPosition(move3);
            this->getObject("player_4_character")->setPosition(move4);
        } else if (type == "select_character") {
            int i;
            in >> i;
            character = i;
        }
    }

    //std::cout << character << std::endl;
    this->getObject("player_1_character")->draw(this->getWindow());
    this->getObject("player_2_character")->draw(this->getWindow());
    this->getObject("player_3_character")->draw(this->getWindow());
    this->getObject("player_4_character")->draw(this->getWindow());

    //this->getObject("player_1_character")->draw(this->getWindow());
    //this->getObject("player_1_character")->setPosition();
    // this->getObject("Second Character")->draw(_window);
}

sf::Vector2f translate;

void ClientScene::events(sf::Event *_event)
{
    sf::Packet out;
    std::string type;
    if (character == 1) {
        type = "move_character_1";
    } else if (character == 2) {
        type = "move_character_2";
    } else if (character == 3) {
        type = "move_character_3";
    } else if (character == 4) {
        type = "move_character_4";
    }
    if (this->getWindow()->hasFocus()) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            std::cout << "W" << std::endl;
            translate.y -= 7.0;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            std::cout << "S" << std::endl;
            translate.y += 7.0;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            std::cout << "A" << std::endl;
            translate.x -= 7.0;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            std::cout << "D" << std::endl;
            translate.x += 7.0;
        }

        if (translate.x != 0.f || translate.y != 0.f)
            translate /= std::sqrt(2.f);

        if (character == 1) {
            this->getObject("player_1_character")->getSprite()->move(translate);
        } else if (character == 2) {
            this->getObject("player_2_character")->getSprite()->move(translate);
        } else if (character == 3) {
            this->getObject("player_3_character")->getSprite()->move(translate);
        } else if (character == 4) {
            this->getObject("player_4_character")->getSprite()->move(translate);
        }

        out << type << translate.x << translate.y;
        this->socket->send(out, "127.0.0.1", 3001);
/*
        if (translate.x != 0 || translate.y != 0) {
            translate /= std::sqrt(2.f);
        } */

        
    }
    //this->getObject("player_1_character")->events(_event);
}