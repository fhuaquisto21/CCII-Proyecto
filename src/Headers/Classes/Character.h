#include <SFML/Graphics.hpp>
#include <stack>

class Character{
    private:
        std::string name;
        std::stack<int>* trash;
        float speed;
        sf::Texture* characterTexture;
        sf::Sprite* characterSprite;
        void movUp();
        void movDown();
        void movLeft();
        void movRight();
    public:
        Character(std::string,float);
        ~Character(){}
        void pushTrash();
        void popTrash();
        void mov(int);
        float getCharacterPosicionX();
        float getCharacterPosicionY();
        sf::Sprite getCharacterSprite();
};