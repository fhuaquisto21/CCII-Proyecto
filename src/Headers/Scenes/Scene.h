#include <SFML/Graphics.hpp>
#include <map>

class Scene
{
private:
    sf::Window *scene;
    std::map<std::string, sf::Texture> textures;
    std::map<std::string, sf::Sprite> sprites;

public:
    Scene(const sf::Window &);
    ~Scene();
    void addSrite(std::string, std::string);
    void draw();
};