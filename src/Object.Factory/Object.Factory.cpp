#include <SFML/Graphics.hpp>
#include "./Object.Factory.h"
#include "./Object/Character/Bob.Character.h"

Object *ObjectFactory::getObject(int _object)
{
    Object *obj;
    switch (_object)
    {
    case gm::Object::BobCharacter:
    {
        obj = new BobCharacter();
        break;
    }
    }
    return obj;
}