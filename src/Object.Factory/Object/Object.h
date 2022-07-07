#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics.hpp>

class Object
{
private:
    std::string type;
    std::string name;
    std::string mode;
    sf::Texture *texture;
    sf::Sprite *sprite;

public:
    Object(std::string, std::string, std::string);
    ~Object();
    void setPosition(sf::Vector2f);
    sf::Vector2f getPosition();
    std::string getName();
    std::string getType();
    std::string getMode();
    sf::Sprite *getSprite();
    sf::Texture *getTexture();
    void setTexture(std::string);
    void setSprite();
    bool isCollitionWith(Object *);
    virtual void draw(sf::RenderWindow *);
    virtual void events(sf::Event *);
};

namespace gm {
    namespace Object {
        enum {
            BobCharacter = 0,
            CharacterCamera = 10,
            GunWeapon = 5,
        };
    }
}

#include "./Object.cpp"

#endif