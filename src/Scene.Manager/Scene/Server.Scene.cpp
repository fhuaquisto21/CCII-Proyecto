#include "./Server.Scene.h"

ServerScene::ServerScene(sf::RenderWindow *_window) : Scene("server", _window)
{
    // std::string h = "Main Character";
    this->listener = new sf::TcpListener;
    this->listener->setBlocking(false);
    this->listener->listen(4000);
    std::cout << sf::IpAddress::getLocalAddress().toString() << std::endl;
    std::cout << this->getMode() << std::endl;
    this->addObject("player_1_character", gm::Object::BobCharacter);
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
    sf::TcpSocket client;
    client.setBlocking(false);
    if (this->listener->accept(client) != sf::Socket::Done)
    {
        std::cout << "Error" << std::endl;
    } else {
        std::cout << "Socket connect" << std::endl;
    }
    this->getObject("player_1_character")->draw(this->getWindow());
    // this->getObject("Second Character")->draw(_window);
}

void ServerScene::events(sf::Event *_event)
{
    this->getObject("player_1_character")->events(_event);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
        SceneManager::get()->push(this->getWindow(), gm::Scene::NoneScene);
    }
}