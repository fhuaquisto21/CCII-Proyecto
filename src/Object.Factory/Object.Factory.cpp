#include <SFML/Graphics.hpp>
#include "./Object.Factory.h"

Object *ObjectFactory::getObject(std::string _mode, int _object)
{
    Object *obj;
    switch (_object)
    {
    case gm::Object::BobCharacter:
    {
        obj = new BobCharacter(_mode);
        break;
    }
    }
    return obj;
}