#include "./Gun.Weapon.h"


GunWeapon::GunWeapon(): Weapon("Gun", 4.f) {
    this->setTexture("./src/Assets/Textures/esfera_de_energia.png");
    this->setSprite();
    this->getSprite()->setPosition(500,440);

}

GunWeapon::~GunWeapon() {}

void GunWeapon::draw(sf::RenderWindow * _window) {
    Weapon::draw(_window);
}

void GunWeapon::events(sf::Event * _event) {
    Weapon::events(_event);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
        std::cout << "Pulso"  << std::endl;
    }   
}
