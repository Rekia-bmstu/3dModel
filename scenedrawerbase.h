#ifndef SCENEDRAWERBASE_H
#define SCENEDRAWERBASE_H
#include "scene.h"
#include <QPicture>

class SceneDrawerBase
{

public:
    virtual void DrawScene(Scene *scene) = 0;
    virtual ~SceneDrawerBase() {}
};

#endif // SCENEDRAWERBASE_H
