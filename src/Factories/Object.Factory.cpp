#include <SFML/Graphics.hpp>
#include "./../Headers/Factories/Object.Factory.h"

Object *ObjectFactory::getObject(int _typeObject, int _object)
{
    Object* obj;
    switch (_typeObject)
    {
    case 0:
        switch (_object)
        {
        case 0:
            obj = new BobCharacter(5.f);
            break;
        }
    default:
        break;
    }

    return obj;
}