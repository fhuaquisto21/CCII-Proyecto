#include "./Test.Scene.h"

TestScene::TestScene(sf::RenderWindow *_window): Scene("none", _window) {
    //std::string h = "Main Character";
    std::cout << gm::Object::BobCharacter << std::endl;
    this->addObject("player_1_character", gm::Object::BobCharacter);
    //this->addObject("player_2_character", gm::Object::BobCharacter);
    //this->addCamera("player_1_camera", sf::FloatRect(0.f, 0.f, (float)(_window->getSize().x), (float)(_window->getSize().y)));
    //this->getObject("Main Character");
}

TestScene::~TestScene() {}

void TestScene::draw() {
    sf::View vpersona = sf::View(sf::FloatRect(0.f, 0.f, (float)(this->getWindow()->getSize().x), (float)(this->getWindow()->getSize().y)));
    //vpersona.setCenter(this->getObject("Main Character")->getPosition());
    //vpersona.move();
    //_window->setView(vpersona);
    this->getObject("player_1_character")->draw(this->getWindow());
    //this->getObject("Second Character")->draw(_window);
}

void TestScene::events(sf::Event *_event) {
    this->getObject("player_1_character")->events(_event);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
        SceneManager::get()->push(this->getWindow(), gm::Scene::ClientScene);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)) {
        SceneManager::get()->push(this->getWindow(), gm::Scene::ServerScene);
    }
}