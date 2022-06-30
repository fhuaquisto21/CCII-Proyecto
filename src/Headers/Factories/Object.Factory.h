#include <SFML/Graphics.hpp>
#include "./../../Classes/Bob.Character.cpp"

/*
class ObjectFactory {
    private:
        std::string type;
        std::string name;
        sf::Texture texture;
        sf::Sprite sprite;
};
*/
class ObjectFactory
{
protected:
    ObjectFactory();

public:
    ObjectFactory(ObjectFactory &_other) = delete;
    void operator=(const ObjectFactory &) = delete;
    static ObjectFactory *GetInstance();
    static Object *getBobCharacter();
};