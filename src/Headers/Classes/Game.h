#include <SFML/Graphics.hpp>
//#include "./../Scenes/ScenesManager.cpp"

class Game
{
private:
    sf::RenderWindow *window;
    sf::VideoMode *size;
    std::string name;
    int styleScreen;
    //ScenesManager* scenesManager;

public:
    Game(sf::VideoMode *, std::string, int);
    ~Game();
    void render();
    void draw();
    void close(sf::Event&);
};