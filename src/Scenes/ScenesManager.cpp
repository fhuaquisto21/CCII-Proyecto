#include <SFML/Graphics.hpp>
#include <stack>
#include "./../Headers/Scenes/ScenesManager.h"

ScenesManager *ScenesManager::scenesManager = nullptr;

ScenesManager *ScenesManager::GetInstance()
{
    if (scenesManager == nullptr)
    {
        scenesManager == new ScenesManager();
    }
    return scenesManager;
}

ScenesManager::ScenesManager()
{

}

sf::View ScenesManager::value() {
    return this->scenes->top();
}