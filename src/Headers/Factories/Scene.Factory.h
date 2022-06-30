#include <SFML/Graphics.hpp>
#include "./../Scenes/Scene.h"

class SceneFactory
{
protected:
    SceneFactory();

public:
    SceneFactory(SceneFactory &_other) = delete;
    void operator=(const SceneFactory &) = delete;
    static Scene *getScene(int);
};