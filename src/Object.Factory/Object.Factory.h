#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include "./Object/Object.h"
#include "./Object/Character/Bob.Character.h"
#include "./Object/Weapon/Gun.Weapon.h"

class ObjectFactory
{
protected:
    ObjectFactory();

public:
    ObjectFactory(ObjectFactory &_other) = delete;
    void operator=(const ObjectFactory &) = delete;
    static Object *getObject(std::string, int);
    
};

#include "./Object.Factory.cpp"

#endif