#include <SFML/Graphics.hpp>
#include "./Object.Factory.h"

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