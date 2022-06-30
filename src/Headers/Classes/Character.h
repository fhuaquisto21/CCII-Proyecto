#include <SFML/Graphics.hpp>
#include <stack>
#include "./../../Classes/Object.cpp"

class Character : public Object
{
private:
    // std::string name;
    // std::stack<int> *trash;
    float speed;
    // sf::Texture *characterTexture;
    // sf::Sprite *characterSprite;
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

public:
    Character(std::string, float);
    ~Character() {}
    //void pushTrash();
    //void popTrash();
    void move(int);
    //float getCharacterPosicionX();
    //float getCharacterPosicionY();
    //sf::Sprite getCharacterSprite();
};