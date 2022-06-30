#include <SFML/Graphics.hpp>
#include "./../../Classes/Bob.Character.cpp"

class ObjectFactory
{
protected:
    ObjectFactory();

public:
    ObjectFactory(ObjectFactory &_other) = delete;
    void operator=(const ObjectFactory &) = delete;
    static ObjectFactory *GetInstance();
    static Object *getObject(int, int);
};