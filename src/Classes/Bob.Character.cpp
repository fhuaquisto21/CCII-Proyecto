#include <SFML/Graphics.hpp>
#include "./../Headers/Classes/Bob.Character.h"

BobCharacter::BobCharacter(std::string _name, float _speed): Character(_name, _speed) {
    this->setTexture("./src/Assets/Textures/bob_character_texture.png");
    this->setSprite();
}