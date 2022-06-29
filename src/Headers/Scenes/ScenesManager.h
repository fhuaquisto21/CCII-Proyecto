#include <SFML/Graphics.hpp>
#include <stack>

class ScenesManager
{
protected:
    static ScenesManager *scenesManager;
    ScenesManager();
    std::stack<sf::View> *scenes;

public:
    ScenesManager(ScenesManager &_other) = delete;
    void operator=(const ScenesManager &) = delete;
    static ScenesManager *GetInstance();
    sf::View value();
};
