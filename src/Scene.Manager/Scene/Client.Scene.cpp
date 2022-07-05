#include "./Client.Scene.h"

ClientScene::ClientScene(sf::RenderWindow *_window) : Scene("client", _window)
{
    // std::string h = "Main Character";
    std::cout << this->getMode() << std::endl;
    this->addObject("player_1_character", gm::Object::BobCharacter);
    // this->addObject("player_2_character", gm::Object::BobCharacter);
    // this->addCamera("player_1_camera", sf::FloatRect(0.f, 0.f, (float)(_window->getSize().x), (float)(_window->getSize().y)));
    // this->getObject("Main Character");
}

ClientScene::~ClientScene() {}

void ClientScene::draw()
{
    //sf::View vpersona = sf::View(sf::FloatRect(0.f, 0.f, (float)(this->getWindow()->getSize().x), (float)(this->getWindow()->getSize().y)));
    // vpersona.setCenter(this->getObject("Main Character")->getPosition());
    // vpersona.move();
    //_window->setView(vpersona);
    sf::TcpSocket socket;
    socket.setBlocking(false);
    if (socket.connect("192.168.0.11", 4000) != sf::Socket::Done)
    {
        std::cout << ": ERROR" << std::endl;
    } else {
        std::cout << ": Conectado" << std::endl;

    }
    this->getObject("player_1_character")->draw(this->getWindow());
    // this->getObject("Second Character")->draw(_window);
}

void ClientScene::events(sf::Event *_event)
{
    this->getObject("player_1_character")->events(_event);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
        SceneManager::get()->push(this->getWindow(), gm::Scene::NoneScene);
    }
}