#include <SFML/Graphics.hpp>
#include "./Test.Scene.h"
#include "./../../Object.Factory/Object/Object.h"

TestScene::TestScene(): Scene() {
    //std::string h = "Main Character";
    std::cout << gm::Object::BobCharacter << std::endl;
    this->addObject("Main Character", gm::Object::BobCharacter);
    //this->getObject("Main Character");
}

TestScene::~TestScene() {}

void TestScene::draw(sf::RenderWindow *_window) {
    this->getObject("Main Character")->draw(_window);
}

void TestScene::events(sf::Event *_event) {
    this->getObject("Main Character")->events(_event);
}