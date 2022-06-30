#include <SFML/Graphics.hpp>

class Object
{
private:
    std::string type;
    std::string name;
    sf::Texture *texture;
    sf::Sprite *sprite;

public:
    Object(std::string, std::string);
    ~Object();
    void setPosition(sf::Vector2f);
    sf::Vector2f getPosition();
    std::string getName();
    std::string getType();
    sf::Sprite *getSprite();
    sf::Texture *getTexture();
    void setTexture(std::string);
    void setSprite();
};