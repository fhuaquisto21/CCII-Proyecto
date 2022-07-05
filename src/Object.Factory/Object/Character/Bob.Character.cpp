#include "./Bob.Character.h"

BobCharacter::BobCharacter(): Character("Bob", 4.f) {
    this->setTexture("./src/Assets/Textures/bob_character_texture.png");
    this->setSprite();
}

BobCharacter::~BobCharacter() {}

void BobCharacter::draw(sf::RenderWindow * _window) {
    Character::draw(_window);
}

void BobCharacter::events(sf::Event * _event) {
    Character::events(_event);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
        std::cout << "Pulso"  << std::endl;
    }   
}