#include <SFML/Graphics.hpp>
#include <map>
#include "./../../Factories/Object.Factory.cpp"
#include "./../../Classes/State.cpp"

class Scene
{
private:
    sf::RenderWindow *scene;
    std::map<std::string, Object *> *objects;
    std::map<std::string, State *> *states;

public:
    Scene(sf::RenderWindow *&);
    ~Scene();
    void addObject(std::string, int, int);
    void addState(std::string, State *);
    sf::RenderWindow *getScene();
    std::map<std::string, Object *> *getObjects();
    std::map<std::string, State *> *getStates();
    virtual void draw();
};

namespace game
{
    namespace Scene
    {
        enum
        {
            Main = 0,
            MenuPrincipal = 1,
            MenuMode = 2,
            MenuPlayers = 3,
            GameLocal = 4,
            GameMultiplayer = 5,
        };
    }
}