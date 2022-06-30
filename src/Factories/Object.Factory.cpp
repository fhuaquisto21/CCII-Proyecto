#include <SFML/Graphics.hpp>
#include "./../Headers/Factories/Object.Factory.h"

Object* ObjectFactory::getBobCharacter() {
    return new BobCharacter("Bob", 6.f);
}