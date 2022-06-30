#include <SFML/Graphics.hpp>
#include "./../Headers/Classes/Bob.Character.h"

BobCharacter::BobCharacter(float _speed): Character("Bob", _speed) {
    this->setTexture("./src/Assets/Textures/bob_character_texture.png");
    this->setSprite();
}