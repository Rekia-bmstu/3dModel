#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H
#include "transformmatrix.h"

class SceneObject
{
public:
    virtual void Transform(TransformMatrix mat) = 0;
    virtual ~SceneObject() {}
};

#endif // SCENEOBJECT_H
