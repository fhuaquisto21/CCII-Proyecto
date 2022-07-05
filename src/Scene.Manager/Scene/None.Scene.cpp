#include <SFML/Graphics.hpp>
#include "./None.Scene.h"

NoneScene::NoneScene(sf::RenderWindow *_window): Scene(_window) {
    //std::string h = "Main Character";
    //std::cout << gm::Object::BobCharacter << std::endl;
    //this->addObject("player_1_character", gm::Object::BobCharacter);
    //this->addObject("player_2_character", gm::Object::BobCharacter);
    //this->addCamera("player_1_camera", sf::FloatRect(0.f, 0.f, (float)(_window->getSize().x), (float)(_window->getSize().y)));
    //this->getObject("Main Character");
    std::cout << "Fuck" << std::endl;
}

NoneScene::~NoneScene() {}

void NoneScene::draw() {
    sf::View vpersona = sf::View(sf::FloatRect(0.f, 0.f, (float)(this->getWindow()->getSize().x), (float)(this->getWindow()->getSize().y)));
    //sf::View vpersona = sf::View(sf::FloatRect(0.f, 0.f, (float)(this->getWindow()->getSize().x), (float)(this->getWindow()->getSize().y)));
    //vpersona.setCenter(this->getObject("Main Character")->getPosition());
    //vpersona.move();
    //_window->setView(vpersona);
    //this->getObject("player_1_character")->draw(this->getWindow());
    //this->getObject("Second Character")->draw(_window);
}

void NoneScene::events(sf::Event *_event) {
    //this->getObject("player_1_character")->events(_event);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) {
        SceneManager *instance = SceneManager::get();
        instance->pop();
    }
}