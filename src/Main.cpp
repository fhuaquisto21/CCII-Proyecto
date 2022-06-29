#include <SFML/Graphics.hpp>
#include "./Classes/Game.cpp"

int main(int argc, char *argv[])
{
    std::string name = "No botes la basura!";
    sf::VideoMode *video = new sf::VideoMode(800, 600);
    Game *game = new Game(video, name, 0);
    game->render();

    return 0;
}