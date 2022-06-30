#include <SFML/Graphics.hpp>

class Player {
    private:
        char* name;
    public:
        Player(const char*);
        ~Player(){}
        void setCharacter(int);
};

